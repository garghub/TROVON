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
static int T_7 F_24 ( void )
{
const struct V_37 * V_38 ;
struct V_39 * V_40 ;
struct V_24 V_41 ;
F_25 () ;
V_40 = F_26 ( NULL , V_42 , & V_38 ) ;
if ( ! V_40 ) {
if ( F_27 ( V_43 ) && F_28 () ) {
T_1 V_44 = F_29 () ;
V_41 . V_45 = 0x7000f800 ;
V_41 . V_46 = 0x7000fbff ;
V_41 . V_47 = V_27 ;
switch ( V_44 ) {
#ifdef F_30
case V_48 :
V_2 -> V_29 = & V_49 ;
break;
#endif
#ifdef F_31
case V_50 :
V_2 -> V_29 = & V_51 ;
break;
#endif
#ifdef F_32
case V_52 :
V_2 -> V_29 = & V_53 ;
break;
#endif
#ifdef F_33
case V_54 :
V_2 -> V_29 = & V_55 ;
break;
#endif
default:
F_34 ( L_3 , V_44 ) ;
break;
}
} else {
return 0 ;
}
} else {
if ( F_35 ( V_40 , 0 , & V_41 ) < 0 ) {
F_36 ( L_4 ) ;
return - V_56 ;
}
V_2 -> V_29 = V_38 -> V_57 ;
}
V_40 = F_37 ( NULL , V_58 ) ;
if ( V_40 ) {
void T_6 * V_23 = F_38 ( V_40 , 0 ) ;
if ( V_23 ) {
F_20 ( V_23 ) ;
F_16 ( V_23 ) ;
} else {
F_36 ( L_5 ) ;
return - V_56 ;
}
}
V_2 -> V_23 = F_39 ( V_41 . V_45 , F_40 ( & V_41 ) ) ;
if ( ! V_2 -> V_23 ) {
F_36 ( L_6 ) ;
return - V_56 ;
}
V_2 -> V_29 -> V_59 ( V_2 ) ;
F_41 ( L_7 ,
V_60 [ V_61 . V_62 ] ,
V_61 . V_63 , V_61 . V_64 ,
V_61 . V_65 ) ;
F_42 ( L_8 ,
V_61 . V_66 , V_61 . V_67 ) ;
return 0 ;
}
