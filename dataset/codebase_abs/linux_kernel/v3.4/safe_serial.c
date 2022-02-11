static T_1 T_2 F_1 ( unsigned char * V_1 , int V_2 , T_1 V_3 )
{
for (; V_2 -- > 0 ; V_3 = F_2 ( V_3 , * V_1 ++ ) ) ;
return V_3 ;
}
static void F_3 ( struct V_4 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned char * V_8 = V_4 -> V_9 ;
unsigned char V_10 = V_4 -> V_11 ;
int V_11 ;
struct V_12 * V_13 ;
T_1 V_3 ;
if ( ! V_10 )
return;
V_13 = F_4 ( & V_6 -> V_6 ) ;
if ( ! V_13 )
return;
if ( ! V_14 )
goto V_15;
V_3 = F_1 ( V_8 , V_10 , V_16 ) ;
if ( V_3 ) {
F_5 ( & V_6 -> V_17 , L_1 , V_18 , V_3 ) ;
goto V_19;
}
V_11 = V_8 [ V_10 - 2 ] >> 2 ;
if ( V_11 > ( V_10 - 2 ) ) {
F_5 ( & V_6 -> V_17 , L_2 ,
V_18 , V_11 , V_10 ) ;
goto V_19;
}
F_6 ( & V_4 -> V_17 -> V_17 , L_3 , V_18 , V_11 ) ;
V_10 = V_11 ;
V_15:
F_7 ( V_13 , V_8 , V_10 ) ;
F_8 ( V_13 ) ;
V_19:
F_9 ( V_13 ) ;
}
static int F_10 ( struct V_5 * V_6 ,
void * V_20 , T_3 V_21 )
{
unsigned char * V_22 = V_20 ;
int V_23 ;
int V_24 ;
int V_25 ;
T_1 V_3 ;
V_24 = V_14 ? 2 : 0 ;
V_23 = F_11 ( & V_6 -> V_26 , V_22 , V_21 - V_24 ,
& V_6 -> V_27 ) ;
if ( ! V_14 )
return V_23 ;
if ( V_28 ) {
V_25 = V_21 ;
memset ( V_22 + V_23 , '0' , V_25 - V_23 - V_24 ) ;
} else {
V_25 = V_23 + V_24 ;
}
V_22 [ V_25 - 2 ] = V_23 << 2 ;
V_22 [ V_25 - 1 ] = 0 ;
V_3 = F_1 ( V_22 , V_25 , V_16 ) ;
V_22 [ V_25 - 2 ] |= V_3 >> 8 ;
V_22 [ V_25 - 1 ] |= V_3 & 0xff ;
return V_25 ;
}
static int F_12 ( struct V_29 * V_30 )
{
switch ( V_30 -> V_31 -> V_32 -> V_33 . V_34 ) {
case V_35 :
break;
case V_36 :
V_28 = 1 ;
break;
default:
return - V_37 ;
}
return 0 ;
}
static int T_4 F_13 ( void )
{
int V_38 ;
F_14 (KERN_INFO KBUILD_MODNAME L_4 DRIVER_VERSION L_5
DRIVER_DESC L_6 ) ;
if ( V_39 || V_40 ) {
F_14 (KERN_INFO KBUILD_MODNAME L_7 ,
vendor, product) ;
for ( V_38 = 0 ; V_38 < F_15 ( V_41 ) ; V_38 ++ ) {
if ( ! V_41 [ V_38 ] . V_42 && ! V_41 [ V_38 ] . V_43 ) {
V_41 [ V_38 ] . V_42 = V_39 ;
V_41 [ V_38 ] . V_43 = V_40 ;
break;
}
}
}
return F_16 ( & V_44 , V_45 ) ;
}
static void T_5 F_17 ( void )
{
F_18 ( & V_44 , V_45 ) ;
}
