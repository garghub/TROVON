static void T_1 F_1 ( struct V_1 * V_2 )
{
T_2 V_3 , V_4 ;
F_2 ( V_5 , V_3 , V_4 ) ;
F_3 ( L_1 , V_3 , V_4 ) ;
if ( V_3 & 0x01 )
V_2 -> V_2 = V_6 ;
else
V_2 -> V_2 = V_7 ;
F_2 ( V_8 , V_3 , V_4 ) ;
F_3 ( L_2 , V_3 , V_4 ) ;
V_3 &= 0x0000007F ;
V_4 &= 0x0000007F ;
if ( V_9 <= V_10 ) {
V_2 -> V_11 = V_2 -> V_12 = V_9 ;
} else {
V_2 -> V_11 = V_10 + V_3 *
( ( V_9 - V_10 ) / 100 ) ;
V_2 -> V_12 = V_10 + V_4 *
( ( V_9 - V_10 ) / 100 ) ;
}
V_2 -> V_13 = 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
T_2 V_3 , V_4 ;
T_2 V_14 , V_15 ;
if ( ! V_2 )
return - V_16 ;
if ( V_9 <= V_10 ) {
V_14 = V_15 = 100 ;
} else {
V_14 = ( V_2 -> V_11 - V_10 ) /
( ( V_9 - V_10 ) / 100 ) ;
V_15 = ( V_2 -> V_12 - V_10 ) /
( ( V_9 - V_10 ) / 100 ) ;
}
if ( V_15 > 100 )
V_15 = 100 ;
if ( V_14 > V_15 )
V_14 = V_15 ;
F_2 ( V_5 , V_3 , V_4 ) ;
V_3 &= 0xFFFFFFFE ;
switch ( V_2 -> V_2 ) {
case V_6 :
V_3 |= 0x00000001 ;
break;
case V_7 :
break;
}
F_5 ( V_5 , V_3 , V_4 ) ;
F_2 ( V_8 , V_3 , V_4 ) ;
V_3 &= 0xFFFFFF80 ;
V_4 &= 0xFFFFFF80 ;
V_3 |= V_14 ;
V_4 |= V_15 ;
F_5 ( V_8 , V_3 , V_4 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return - V_16 ;
V_2 -> V_13 = 0 ;
F_7 ( V_2 ,
V_2 -> V_17 . V_18 ,
V_2 -> V_17 . V_19 ) ;
if ( ( V_2 -> V_2 != V_7 ) &&
( V_2 -> V_2 != V_6 ) )
return - V_16 ;
return 0 ;
}
static unsigned int F_8 ( unsigned int V_13 )
{
T_2 V_20 , V_21 , V_22 , V_23 ;
if ( V_13 )
return 0 ;
F_9 ( 0x80860007 , & V_20 , & V_21 , & V_22 , & V_23 ) ;
F_3 ( L_3 , V_20 ) ;
return V_20 * 1000 ;
}
static int T_1 F_10 ( unsigned int * V_24 ,
unsigned int * V_25 )
{
T_2 V_3 , V_4 ;
T_2 V_26 , V_27 ;
T_2 V_20 , V_21 , V_22 , V_23 ;
T_2 V_28 ;
struct V_29 * V_30 = & F_11 ( 0 ) ;
if ( ! V_24 || ! V_25 )
return - V_16 ;
if ( F_12 ( V_30 , V_31 ) ) {
F_2 ( V_32 , V_3 , V_4 ) ;
F_5 ( V_32 , V_4 , V_4 ) ;
F_2 ( V_33 , V_3 , V_4 ) ;
* V_24 = V_3 * 1000 ;
F_5 ( V_32 , 0 , V_4 ) ;
F_2 ( V_33 , V_3 , V_4 ) ;
* V_25 = V_3 * 1000 ;
F_3 ( L_4 ,
* V_24 , * V_25 ) ;
if ( * V_24 > * V_25 )
* V_24 = * V_25 ;
return 0 ;
}
* V_25 = ( V_34 / 1000 ) ;
* V_25 = * V_25 * 1000 ;
F_3 ( L_5 , * V_25 ) ;
F_2 ( V_8 , V_3 , V_4 ) ;
V_26 = V_3 & 0x0000007F ;
V_27 = V_4 & 0x0000007F ;
F_9 ( 0x80860007 , & V_20 , & V_21 , & V_22 , & V_23 ) ;
for ( V_28 = 80 ; V_28 > 0 && V_22 > 90 ; V_28 -= 10 ) {
V_3 &= 0xFFFFFF80 ;
V_4 &= 0xFFFFFF80 ;
V_4 |= V_28 ;
F_5 ( V_8 , V_3 , V_4 ) ;
F_9 ( 0x80860007 , & V_20 , & V_21 , & V_22 , & V_23 ) ;
F_5 ( V_8 , V_26 , V_27 ) ;
}
F_3 ( L_6 , V_22 , V_20 ) ;
V_21 = ( ( ( V_34 / 1000 ) * V_22 ) / 100 ) ;
if ( ( V_22 > 95 ) || ( V_22 == 0 ) || ( V_20 < V_21 ) )
return - V_35 ;
V_23 = ( ( V_20 - V_21 ) * 100 ) / ( 100 - V_22 ) ;
* V_24 = V_23 * 1000 ;
F_3 ( L_7 , * V_24 ) ;
if ( * V_24 > * V_25 )
* V_24 = * V_25 ;
return 0 ;
}
static int T_1 F_13 ( struct V_1 * V_2 )
{
int V_36 = 0 ;
if ( V_2 -> V_13 != 0 )
return - V_37 ;
V_36 = F_10 ( & V_10 , & V_9 ) ;
if ( V_36 )
return V_36 ;
V_2 -> V_17 . V_18 = V_10 ;
V_2 -> V_17 . V_19 = V_9 ;
V_2 -> V_17 . V_38 = V_39 ;
F_1 ( V_2 ) ;
return 0 ;
}
static int T_3 F_14 ( void )
{
struct V_29 * V_30 = & F_11 ( 0 ) ;
if ( V_30 -> V_40 != V_41 ||
! F_12 ( V_30 , V_42 ) )
return - V_37 ;
return F_15 ( & V_43 ) ;
}
static void T_4 F_16 ( void )
{
F_17 ( & V_43 ) ;
}
