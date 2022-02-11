static T_1 F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
T_2 V_4 ;
V_4 = V_2 -> V_5 ( V_2 , F_2 ( V_3 , 4 ) ) ;
V_4 >>= ( V_3 % 4 ) * 8 ;
V_4 &= 0xff ;
return V_4 ;
}
static T_3 F_3 ( struct V_6 * V_7 , struct V_8 * V_9 ,
struct V_10 * V_11 , char * V_12 ,
T_4 V_13 , T_5 V_14 )
{
struct V_15 * V_16 = F_4 ( V_9 ) ;
struct V_1 * V_2 = F_5 ( V_16 ) ;
int V_17 ;
if ( V_13 < 0 || V_13 >= V_11 -> V_14 )
return 0 ;
if ( V_14 > V_11 -> V_14 - V_13 )
V_14 = V_11 -> V_14 - V_13 ;
for ( V_17 = 0 ; V_17 < V_14 ; V_17 ++ )
V_12 [ V_17 ] = F_1 ( V_2 , V_13 + V_17 ) ;
return V_17 ;
}
static int F_6 ( struct V_15 * V_16 , unsigned int V_14 ,
const struct V_18 * V_19 )
{
V_20 . V_14 = V_14 ;
return F_7 ( V_16 , & V_20 ) ;
}
static int F_8 ( struct V_21 * V_22 )
{
void T_6 * V_23 = V_2 -> V_23 ;
struct V_24 * V_25 ;
int V_26 ;
V_25 = F_9 ( V_22 , V_27 , 0 ) ;
V_2 -> V_23 = F_10 ( & V_22 -> V_16 , V_25 ) ;
if ( F_11 ( V_2 -> V_23 ) )
return F_12 ( V_2 -> V_23 ) ;
V_2 -> V_28 = F_13 ( & V_22 -> V_16 , L_1 ) ;
if ( F_11 ( V_2 -> V_28 ) ) {
F_14 ( & V_22 -> V_16 , L_2 ,
F_12 ( V_2 -> V_28 ) ) ;
return F_12 ( V_2 -> V_28 ) ;
}
F_15 ( V_22 , V_2 ) ;
V_2 -> V_16 = & V_22 -> V_16 ;
if ( V_2 -> V_29 -> V_30 ) {
V_26 = V_2 -> V_29 -> V_30 ( V_2 ) ;
if ( V_26 < 0 )
return V_26 ;
}
if ( F_6 ( & V_22 -> V_16 , V_2 -> V_29 -> V_19 -> V_14 ,
V_2 -> V_29 -> V_19 ) )
return - V_31 ;
F_16 ( V_23 ) ;
return 0 ;
}
bool T_7 F_17 ( unsigned int V_32 )
{
unsigned int V_3 = V_2 -> V_29 -> V_19 -> V_32 + V_32 * 4 ;
return V_2 -> V_33 ( V_2 , V_3 ) & 1 ;
}
T_2 T_7 F_18 ( unsigned int V_3 )
{
return V_2 -> V_33 ( V_2 , V_3 ) ;
}
int F_19 ( unsigned long V_3 , T_2 * V_34 )
{
if ( ! V_2 -> V_5 )
return - V_35 ;
* V_34 = V_2 -> V_5 ( V_2 , V_3 ) ;
return 0 ;
}
static void F_20 ( void T_6 * V_23 )
{
T_2 V_36 ;
V_36 = F_21 ( V_23 + 0x48 ) ;
V_36 |= 1 << 28 ;
F_22 ( V_36 , V_23 + 0x48 ) ;
V_36 = F_23 ( V_23 + 0x14 ) ;
V_36 |= 1 << 7 ;
F_22 ( V_36 , V_23 + 0x14 ) ;
}
struct V_15 * T_7 F_24 ( void )
{
struct V_37 * V_11 ;
struct V_38 * V_16 ;
V_11 = F_25 ( sizeof( * V_11 ) , V_39 ) ;
if ( ! V_11 )
return NULL ;
V_11 -> V_40 = F_26 ( V_39 , L_3 ) ;
V_11 -> V_41 = F_26 ( V_39 , L_4 , V_42 . V_41 ) ;
V_11 -> V_43 = F_26 ( V_39 , L_5 , F_27 () ) ;
V_16 = F_28 ( V_11 ) ;
if ( F_11 ( V_16 ) ) {
F_29 ( V_11 -> V_43 ) ;
F_29 ( V_11 -> V_41 ) ;
F_29 ( V_11 -> V_40 ) ;
F_29 ( V_11 ) ;
return F_30 ( V_16 ) ;
}
return F_31 ( V_16 ) ;
}
static int T_7 F_32 ( void )
{
const struct V_44 * V_45 ;
struct V_46 * V_47 ;
struct V_24 V_48 ;
F_33 () ;
V_47 = F_34 ( NULL , V_49 , & V_45 ) ;
if ( ! V_47 ) {
if ( F_35 ( V_50 ) && F_36 () ) {
T_1 V_51 = F_27 () ;
V_48 . V_52 = 0x7000f800 ;
V_48 . V_53 = 0x7000fbff ;
V_48 . V_54 = V_27 ;
switch ( V_51 ) {
#ifdef F_37
case V_55 :
V_2 -> V_29 = & V_56 ;
break;
#endif
#ifdef F_38
case V_57 :
V_2 -> V_29 = & V_58 ;
break;
#endif
#ifdef F_39
case V_59 :
V_2 -> V_29 = & V_60 ;
break;
#endif
#ifdef F_40
case V_61 :
V_2 -> V_29 = & V_62 ;
break;
#endif
default:
F_41 ( L_6 , V_51 ) ;
break;
}
} else {
return 0 ;
}
} else {
if ( F_42 ( V_47 , 0 , & V_48 ) < 0 ) {
F_43 ( L_7 ) ;
return - V_63 ;
}
V_2 -> V_29 = V_45 -> V_64 ;
}
V_47 = F_44 ( NULL , V_65 ) ;
if ( V_47 ) {
void T_6 * V_23 = F_45 ( V_47 , 0 ) ;
if ( V_23 ) {
F_20 ( V_23 ) ;
F_16 ( V_23 ) ;
} else {
F_43 ( L_8 ) ;
return - V_63 ;
}
}
V_2 -> V_23 = F_46 ( V_48 . V_52 , F_47 ( & V_48 ) ) ;
if ( ! V_2 -> V_23 ) {
F_43 ( L_9 ) ;
return - V_63 ;
}
V_2 -> V_29 -> V_66 ( V_2 ) ;
F_48 ( L_10 ,
V_67 [ V_42 . V_41 ] ,
V_42 . V_68 , V_42 . V_69 ,
V_42 . V_70 ) ;
F_49 ( L_11 ,
V_42 . V_71 , V_42 . V_72 ) ;
return 0 ;
}
static int T_7 F_50 ( void )
{
struct V_46 * V_47 ;
struct V_15 * V_29 ;
V_47 = F_44 ( NULL , V_49 ) ;
if ( ! V_47 )
return 0 ;
F_51 ( V_47 ) ;
V_29 = F_24 () ;
if ( F_11 ( V_29 ) ) {
F_43 ( L_12 , F_12 ( V_29 ) ) ;
return F_12 ( V_29 ) ;
}
return 0 ;
}
