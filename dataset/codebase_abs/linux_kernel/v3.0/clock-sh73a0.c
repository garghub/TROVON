static unsigned long F_1 ( struct V_1 * V_1 )
{
return V_1 -> V_2 -> V_3 / 2 ;
}
static unsigned long F_2 ( struct V_1 * V_1 )
{
unsigned long V_4 = 1 ;
if ( F_3 ( V_5 ) & ( 1 << V_1 -> V_6 ) ) {
V_4 = ( ( ( F_3 ( V_1 -> V_7 ) >> 24 ) & 0x3f ) + 1 ) ;
switch ( V_1 -> V_6 ) {
case 1 :
case 2 :
if ( F_3 ( V_1 -> V_7 ) & ( 1 << 20 ) )
V_4 *= 2 ;
}
}
return V_1 -> V_2 -> V_3 * V_4 ;
}
static void F_4 ( struct V_1 * V_1 )
{
unsigned long V_8 ;
V_8 = F_3 ( V_9 ) ;
V_8 |= ( 1 << 31 ) ;
F_5 ( V_8 , V_9 ) ;
}
void T_1 F_6 ( void )
{
int V_10 , V_11 = 0 ;
F_5 ( 0x108 , V_12 ) ;
F_5 ( 0x108 , V_13 ) ;
F_5 ( 0x108 , V_14 ) ;
switch ( ( F_3 ( V_15 ) >> 24 ) & 0x03 ) {
case 0 :
V_16 . V_2 = & V_17 ;
break;
case 1 :
V_16 . V_2 = & V_18 ;
break;
case 2 :
V_16 . V_2 = & V_19 ;
break;
case 3 :
V_16 . V_2 = & V_20 ;
break;
}
for ( V_10 = 0 ; ! V_11 && ( V_10 < F_7 ( V_21 ) ) ; V_10 ++ )
V_11 = F_8 ( V_21 [ V_10 ] ) ;
if ( ! V_11 )
V_11 = F_9 ( V_22 , V_23 , & V_24 ) ;
if ( ! V_11 )
V_11 = F_10 ( V_25 , V_26 ) ;
if ( ! V_11 )
V_11 = F_11 ( V_27 , V_28 ) ;
F_12 ( V_29 , F_7 ( V_29 ) ) ;
if ( ! V_11 )
F_13 () ;
else
F_14 ( L_1 ) ;
}
