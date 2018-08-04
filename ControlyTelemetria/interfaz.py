#!/usr/bin/python
try:
    import wx
except ImportError:
    raise ImportError,"Se requiere el modulo wxPython"

class simpleapp_wx(wx.Frame):

   def __init__(self,parent,id,title):
        wx.Frame.__init__(self,parent,id,title)
        self.parent = parent
        self.initialize()

   def initialize(self):
        grilla = wx.GridBagSizer()
        self.entrada = wx.TextCtrl(self,-1,value=u"Ingrese un texto:")
        grilla.Add(self.entrada,(0,0),(1,1),wx.EXPAND)
        boton = wx.Button(self,-1,label="Pulsame !")
        grilla.Add(boton, (0,1))
        self.etiqueta = wx.StaticText(self,-1,label=u'Hola !')
        self.etiqueta.SetBackgroundColour(wx.BLUE)
        self.etiqueta.SetForegroundColour(wx.WHITE)
        grilla.Add( self.etiqueta, (1,0),(1,2), wx.EXPAND )
        grilla.AddGrowableCol(0)
        self.SetSizerAndFit(grilla)
        self.Show(True)

if __name__ == "__main__":
    app = wx.App()
    frame = simpleapp_wx(None,-1,'Mi aplicacion')
    app.MainLoop()
