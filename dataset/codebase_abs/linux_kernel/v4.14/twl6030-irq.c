static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , void * V_4 )
{
int V_5 ;
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
switch ( V_3 ) {
case V_9 :
V_5 = F_3 ( & V_7 -> V_10 ) ;
if ( V_5 && ! V_7 -> V_11 ) {
if ( F_4 ( V_7 -> V_12 ) )
F_5 ( L_1 ) ;
else
V_7 -> V_11 = true ;
} else if ( ! V_5 && V_7 -> V_11 ) {
F_6 ( V_7 -> V_12 ) ;
V_7 -> V_11 = false ;
}
F_7 ( V_7 -> V_12 ) ;
break;
case V_13 :
F_8 ( V_7 -> V_12 ) ;
break;
default:
break;
}
return V_14 ;
}
static T_1 F_9 ( int V_15 , void * V_16 )
{
int V_17 , V_18 ;
union {
T_2 V_19 [ 4 ] ;
T_3 V_20 ;
} V_21 ;
T_4 V_20 ;
struct V_6 * V_7 = V_16 ;
V_18 = F_10 ( V_22 , V_21 . V_19 , V_23 , 3 ) ;
if ( V_18 ) {
F_11 ( L_2 , V_18 ) ;
return V_24 ;
}
V_21 . V_19 [ 3 ] = 0 ;
if ( V_21 . V_19 [ 2 ] & 0x10 )
V_21 . V_19 [ 2 ] |= 0x08 ;
V_20 = F_12 ( V_21 . V_20 ) ;
for ( V_17 = 0 ; V_20 ; V_20 >>= 1 , V_17 ++ )
if ( V_20 & 0x1 ) {
int V_25 =
F_13 ( V_7 -> V_26 ,
V_7 -> V_27 [ V_17 ] ) ;
if ( V_25 )
F_14 ( V_25 ) ;
else
F_5 ( L_3 ,
V_17 ) ;
F_15 ( L_4 ,
V_17 , V_25 ) ;
}
V_18 = F_16 ( V_22 , 0x00 , V_23 ) ;
if ( V_18 )
F_11 ( L_5 ) ;
return V_24 ;
}
static int F_17 ( struct V_28 * V_29 , unsigned int V_30 )
{
struct V_6 * V_7 = F_18 ( V_29 ) ;
if ( V_30 )
F_19 ( & V_7 -> V_10 ) ;
else
F_20 ( & V_7 -> V_10 ) ;
return 0 ;
}
int F_21 ( T_2 V_31 , T_2 V_32 )
{
int V_18 ;
T_2 V_33 ;
V_18 = F_22 ( V_22 , & V_33 ,
V_23 + V_32 ) ;
V_33 &= ( ~ ( V_31 ) ) ;
V_18 |= F_16 ( V_22 , V_33 ,
V_23 + V_32 ) ;
return V_18 ;
}
int F_23 ( T_2 V_31 , T_2 V_32 )
{
int V_18 ;
T_2 V_34 ;
V_18 = F_22 ( V_22 , & V_34 ,
V_23 + V_32 ) ;
V_34 |= ( V_31 ) ;
V_18 |= F_16 ( V_22 , V_34 ,
V_23 + V_32 ) ;
return V_18 ;
}
int F_24 ( void )
{
int V_18 ;
T_2 V_35 = 0 ;
F_21 ( V_36 ,
V_37 ) ;
F_21 ( V_36 ,
V_38 ) ;
V_18 = F_22 ( V_39 , & V_35 , V_40 ) ;
if ( V_18 < 0 ) {
F_5 ( L_6 , V_18 ) ;
return V_18 ;
}
V_35 &= ~ V_41 ;
V_35 |= V_42 ;
V_18 = F_16 ( V_39 , V_35 , V_40 ) ;
if ( V_18 < 0 ) {
F_5 ( L_7 , V_18 ) ;
return V_18 ;
}
V_18 = F_22 ( V_39 , & V_35 ,
V_43 ) ;
if ( V_18 < 0 ) {
F_5 ( L_8 ,
V_18 ) ;
return V_18 ;
}
V_35 &= ~ ( V_44 | V_45 ) ;
V_18 = F_16 ( V_39 , V_35 ,
V_43 ) ;
if ( V_18 < 0 ) {
F_5 ( L_9 ,
V_18 ) ;
return V_18 ;
}
return F_13 ( V_6 -> V_26 ,
V_46 ) ;
}
int F_25 ( struct V_47 * V_48 , int V_49 )
{
int V_18 = - V_50 ;
T_2 V_51 = 0 ;
struct V_52 * V_53 = F_26 ( V_48 ) ;
if ( V_53 -> V_54 ) {
F_5 ( L_10 , V_53 -> V_54 , V_55 ) ;
return V_18 ;
}
V_18 = F_22 ( V_39 , & V_51 ,
V_40 ) ;
if ( V_18 >= 0 )
V_18 = V_51 & V_56 ;
return V_18 ;
}
static int F_27 ( struct V_26 * V_29 , unsigned int V_57 ,
T_5 V_58 )
{
struct V_6 * V_7 = V_29 -> V_59 ;
F_28 ( V_57 , V_7 ) ;
F_29 ( V_57 , & V_7 -> V_60 , V_61 ) ;
F_30 ( V_57 , true ) ;
F_31 ( V_57 , V_7 -> V_12 ) ;
F_32 ( V_57 ) ;
return 0 ;
}
static void F_33 ( struct V_26 * V_29 , unsigned int V_57 )
{
F_29 ( V_57 , NULL , NULL ) ;
F_28 ( V_57 , NULL ) ;
}
int F_34 ( struct V_47 * V_48 , int V_62 )
{
struct V_63 * V_64 = V_48 -> V_65 ;
int V_66 ;
int V_67 ;
T_2 V_68 [ 3 ] ;
const struct V_69 * V_70 ;
V_70 = F_35 ( V_71 , V_48 ) ;
if ( ! V_70 || ! V_70 -> V_16 ) {
F_36 ( V_48 , L_11 ) ;
return - V_72 ;
}
V_66 = V_73 ;
V_6 = F_37 ( V_48 , sizeof( * V_6 ) , V_74 ) ;
if ( ! V_6 ) {
F_36 ( V_48 , L_12 ) ;
return - V_75 ;
}
V_68 [ 0 ] = 0xFF ;
V_68 [ 1 ] = 0xFF ;
V_68 [ 2 ] = 0xFF ;
V_67 = F_38 ( V_22 , & V_68 [ 0 ] , V_76 , 3 ) ;
V_67 |= F_38 ( V_22 , & V_68 [ 0 ] , V_77 , 3 ) ;
V_67 |= F_38 ( V_22 , & V_68 [ 0 ] , V_23 , 3 ) ;
if ( V_67 < 0 ) {
F_36 ( V_48 , L_13 , V_67 ) ;
return V_67 ;
}
V_6 -> V_60 = V_78 ;
V_6 -> V_60 . V_79 = L_14 ;
V_6 -> V_60 . V_80 = NULL ;
V_6 -> V_60 . V_81 = F_17 ;
V_6 -> V_8 . V_82 = F_1 ;
F_39 ( & V_6 -> V_10 , 0 ) ;
V_6 -> V_27 = V_70 -> V_16 ;
V_6 -> V_26 =
F_40 ( V_64 , V_66 ,
& V_83 , V_6 ) ;
if ( ! V_6 -> V_26 ) {
F_36 ( V_48 , L_15 ) ;
return - V_75 ;
}
F_41 ( V_48 , L_16 , V_62 ) ;
V_67 = F_42 ( V_62 , NULL , F_9 ,
V_84 , L_17 , V_6 ) ;
if ( V_67 < 0 ) {
F_36 ( V_48 , L_18 , V_62 , V_67 ) ;
goto V_85;
}
V_6 -> V_12 = V_62 ;
F_43 ( & V_6 -> V_8 ) ;
return 0 ;
V_85:
F_44 ( V_6 -> V_26 ) ;
return V_67 ;
}
int F_45 ( void )
{
if ( V_6 && V_6 -> V_12 ) {
F_46 ( & V_6 -> V_8 ) ;
F_47 ( V_6 -> V_12 , NULL ) ;
}
return 0 ;
}
