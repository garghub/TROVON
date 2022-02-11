static void
T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 , T_2 V_4 )
{
int V_5 ;
V_6 . V_7 = V_2 ;
V_6 . V_3 = V_3 ;
if ( F_2 () >= V_8 ) {
V_5 = F_3 ( V_4 , V_9 - 1 ,
( unsigned long * ) & V_10 . V_11 ) ;
V_10 . V_12 = V_10 . V_11
+ V_9 - 1 ;
} else {
V_5 = F_3 ( V_4 , V_13 - 1 ,
( unsigned long * ) & V_10 . V_11 ) ;
V_10 . V_12 = V_10 . V_11
+ V_13 - 1 ;
}
if ( V_5 < 0 ) {
F_4 ( L_1 ) ;
return;
}
if ( F_5 ( & V_14 ) < 0 )
F_4 ( L_2 ) ;
}
void
T_1 F_6 ( struct V_1 * V_15 ,
T_2 V_3 , T_2 V_4 )
{
V_16 . V_4 = V_4 ;
V_16 . V_7 = V_15 ;
V_16 . V_3 = V_3 ;
F_7 ( & V_16 ) ;
}
void
T_1 F_8 ( struct V_1 * V_17 ,
T_2 V_3 , T_2 V_4 , int V_18 )
{
V_19 . V_4 = V_4 ;
V_19 . V_7 = V_17 ;
V_19 . V_3 = V_3 ;
V_19 . V_20 = V_18 ;
V_19 . V_21 = V_22 ;
F_9 ( & V_19 ) ;
}
static T_2 F_10 ( void )
{
T_2 V_4 = 0 ;
void T_3 * V_23 ;
V_23 = F_11 ( V_24 , 4096 ) ;
if ( ! V_23 )
return - V_25 ;
if ( ! ( F_12 ( V_23 + V_26 ) ) )
goto V_27;
V_4 = F_12 ( V_23 + V_28 ) & 0xf ;
if ( F_2 () >= V_8 )
V_4 = ( ( V_4 & 8 ) >> 3 ) | ( ( V_4 & 4 ) >> 1 ) |
( ( V_4 & 2 ) << 1 ) | ( ( V_4 & 1 ) << 3 ) ;
else
V_4 = ( ( V_4 & 4 ) >> 2 ) | ( V_4 & 2 ) | ( ( V_4 & 1 ) << 2 ) ;
V_27:
F_13 ( V_23 ) ;
return V_4 ;
}
void T_1 F_14 ( struct V_29 V_30 [] ,
char V_31 [] [ V_32 ] , int V_18 )
{
T_2 V_4 = 0 ;
T_2 V_33 = V_32 + 1 ;
T_2 V_34 = V_32 + 1 ;
T_2 V_35 = V_32 + 1 ;
T_2 V_36 ;
unsigned char * V_37 = NULL ;
V_36 = F_10 () ;
if ( V_36 >= V_38 ) {
F_4 ( L_3 , V_39 , V_4 ) ;
return;
}
V_37 = ( unsigned char * ) ( V_31 [ V_36 ] ) ;
while ( V_4 < V_32 ) {
switch ( V_37 [ V_4 ] ) {
case V_40 :
if ( V_33 > V_32 )
V_33 = V_4 ;
break;
case V_41 :
if ( V_34 > V_32 )
V_34 = V_4 ;
break;
case V_42 :
if ( V_35 > V_32 )
V_35 = V_4 ;
break;
}
V_4 ++ ;
}
if ( V_33 > V_32 )
F_4 ( L_4 ) ;
else
F_1 ( V_30 [ 0 ] . V_7 ,
V_30 [ 0 ] . V_3 , V_33 ) ;
if ( V_35 > V_32 )
F_4 ( L_5 ) ;
else
F_6 ( V_30 [ 1 ] . V_7 ,
V_30 [ 1 ] . V_3 , V_35 ) ;
if ( V_34 > V_32 )
F_4 ( L_6 ) ;
else
F_8 ( V_30 [ 2 ] . V_7 ,
V_30 [ 2 ] . V_3 , V_34 , V_18 ) ;
}
