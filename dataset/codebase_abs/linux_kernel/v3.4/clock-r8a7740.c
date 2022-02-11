static unsigned long F_1 ( struct V_1 * V_1 )
{
return V_1 -> V_2 -> V_3 / ( int ) ( V_1 -> V_4 ) ;
}
static unsigned long F_2 ( struct V_1 * V_1 )
{
unsigned long V_5 = 1 ;
if ( F_3 ( V_6 ) & ( 1 << 14 ) )
V_5 = ( ( F_3 ( V_1 -> V_7 ) >> 24 ) & 0x7f ) + 1 ;
return V_1 -> V_2 -> V_3 * V_5 ;
}
static void F_4 ( struct V_1 * V_1 )
{
unsigned long V_8 ;
V_8 = F_3 ( V_9 ) ;
V_8 |= ( 1 << 31 ) ;
F_5 ( V_8 , V_9 ) ;
}
void T_1 F_6 ( T_2 V_10 )
{
int V_11 , V_12 = 0 ;
if ( V_10 & V_13 )
V_14 . V_2 = & V_15 ;
else
V_14 . V_2 = & V_16 ;
switch ( V_10 & ( V_17 | V_13 ) ) {
case V_17 | V_13 :
V_18 . V_2 = & V_19 ;
break;
case V_17 :
V_18 . V_2 = & V_20 ;
break;
case V_13 :
default:
V_18 . V_2 = & V_21 ;
break;
}
for ( V_11 = 0 ; ! V_12 && ( V_11 < F_7 ( V_22 ) ) ; V_11 ++ )
V_12 = F_8 ( V_22 [ V_11 ] ) ;
if ( ! V_12 )
V_12 = F_9 ( V_23 , V_24 , & V_25 ) ;
if ( ! V_12 )
V_12 = F_10 ( V_26 , V_27 ) ;
if ( ! V_12 )
V_12 = F_11 ( V_28 , V_29 ) ;
F_12 ( V_30 , F_7 ( V_30 ) ) ;
if ( ! V_12 )
F_13 () ;
else
F_14 ( L_1 ) ;
}
