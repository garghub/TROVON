struct V_1 * T_1 F_1 ( struct V_1 * V_2 )
{
return (struct V_1 * ) F_2 ( V_3 , V_2 ) ;
}
static inline int F_3 ( union V_4 type )
{
switch ( type . V_5 ) {
case V_6 :
case V_7 :
return V_8 ;
case V_9 :
return V_10 ;
case V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
return V_16 ;
default:
F_4 () ;
}
while( 1 ) ;
}
static inline int F_5 ( union V_4 type )
{
switch ( type . V_17 ) {
case V_18 :
case V_19 :
return V_8 ;
case V_20 :
return V_10 ;
case V_21 :
case V_22 :
case V_23 :
case V_24 :
case V_25 :
return V_16 ;
default:
F_4 () ;
}
while( 1 ) ;
}
static int T_1 F_6 ( union V_4 type )
{
if ( V_26 & V_27 )
return F_3 ( type ) ;
return F_5 ( type ) ;
}
void T_1 F_7 ( void )
{
struct V_1 * V_28 ;
#ifdef F_8
int V_29 = 0 ;
F_9 ( L_1 ) ;
V_28 = F_1 ( V_30 ) ;
while( V_28 ) {
F_9 ( L_2 ,
V_29 , V_28 , V_28 -> V_31 , V_28 -> V_32 , F_10 ( V_28 -> type ) ) ;
V_28 = F_1 ( V_28 ) ;
V_29 ++ ;
}
#endif
V_28 = V_30 ;
while ( ( V_28 = F_1 ( V_28 ) ) ) {
unsigned long V_31 , V_33 ;
long type ;
V_31 = V_28 -> V_31 << V_34 ;
V_33 = V_28 -> V_32 << V_34 ;
type = F_6 ( V_28 -> type ) ;
F_11 ( V_31 , V_33 , type ) ;
}
}
void T_1 F_12 ( void )
{
unsigned long V_35 ;
int V_29 ;
if ( V_26 & V_36 )
return;
for ( V_29 = 0 ; V_29 < V_37 . V_38 ; V_29 ++ ) {
if ( V_37 . V_39 [ V_29 ] . type != V_10 )
continue;
V_35 = V_37 . V_39 [ V_29 ] . V_35 ;
F_13 ( L_3 ,
V_35 , V_35 + V_37 . V_39 [ V_29 ] . V_33 ) ;
}
}
