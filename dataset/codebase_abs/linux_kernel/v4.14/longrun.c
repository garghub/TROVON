static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 , V_4 ;
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
T_1 V_3 , V_4 ;
T_1 V_14 , V_15 ;
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
F_7 ( V_2 ) ;
if ( ( V_2 -> V_2 != V_7 ) &&
( V_2 -> V_2 != V_6 ) )
return - V_16 ;
return 0 ;
}
static unsigned int F_8 ( unsigned int V_13 )
{
T_1 V_17 , V_18 , V_19 , V_20 ;
if ( V_13 )
return 0 ;
F_9 ( 0x80860007 , & V_17 , & V_18 , & V_19 , & V_20 ) ;
F_3 ( L_3 , V_17 ) ;
return V_17 * 1000 ;
}
static int F_10 ( unsigned int * V_21 ,
unsigned int * V_22 )
{
T_1 V_3 , V_4 ;
T_1 V_23 , V_24 ;
T_1 V_17 , V_18 , V_19 , V_20 ;
T_1 V_25 ;
struct V_26 * V_27 = & F_11 ( 0 ) ;
if ( ! V_21 || ! V_22 )
return - V_16 ;
if ( F_12 ( V_27 , V_28 ) ) {
F_2 ( V_29 , V_3 , V_4 ) ;
F_5 ( V_29 , V_4 , V_4 ) ;
F_2 ( V_30 , V_3 , V_4 ) ;
* V_21 = V_3 * 1000 ;
F_5 ( V_29 , 0 , V_4 ) ;
F_2 ( V_30 , V_3 , V_4 ) ;
* V_22 = V_3 * 1000 ;
F_3 ( L_4 ,
* V_21 , * V_22 ) ;
if ( * V_21 > * V_22 )
* V_21 = * V_22 ;
return 0 ;
}
* V_22 = ( V_31 / 1000 ) ;
* V_22 = * V_22 * 1000 ;
F_3 ( L_5 , * V_22 ) ;
F_2 ( V_8 , V_3 , V_4 ) ;
V_23 = V_3 & 0x0000007F ;
V_24 = V_4 & 0x0000007F ;
F_9 ( 0x80860007 , & V_17 , & V_18 , & V_19 , & V_20 ) ;
for ( V_25 = 80 ; V_25 > 0 && V_19 > 90 ; V_25 -= 10 ) {
V_3 &= 0xFFFFFF80 ;
V_4 &= 0xFFFFFF80 ;
V_4 |= V_25 ;
F_5 ( V_8 , V_3 , V_4 ) ;
F_9 ( 0x80860007 , & V_17 , & V_18 , & V_19 , & V_20 ) ;
F_5 ( V_8 , V_23 , V_24 ) ;
}
F_3 ( L_6 , V_19 , V_17 ) ;
V_18 = ( ( ( V_31 / 1000 ) * V_19 ) / 100 ) ;
if ( ( V_19 > 95 ) || ( V_19 == 0 ) || ( V_17 < V_18 ) )
return - V_32 ;
V_20 = ( ( V_17 - V_18 ) * 100 ) / ( 100 - V_19 ) ;
* V_21 = V_20 * 1000 ;
F_3 ( L_7 , * V_21 ) ;
if ( * V_21 > * V_22 )
* V_21 = * V_22 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
int V_33 = 0 ;
if ( V_2 -> V_13 != 0 )
return - V_34 ;
V_33 = F_10 ( & V_10 , & V_9 ) ;
if ( V_33 )
return V_33 ;
V_2 -> V_35 . V_36 = V_10 ;
V_2 -> V_35 . V_37 = V_9 ;
F_1 ( V_2 ) ;
return 0 ;
}
static int T_2 F_14 ( void )
{
if ( ! F_15 ( V_38 ) )
return - V_34 ;
return F_16 ( & V_39 ) ;
}
static void T_3 F_17 ( void )
{
F_18 ( & V_39 ) ;
}
