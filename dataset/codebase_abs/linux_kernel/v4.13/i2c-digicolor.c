static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
F_2 ( V_3 | V_4 , V_2 -> V_5 + V_6 ) ;
}
static T_1 F_3 ( struct V_7 * V_8 )
{
T_1 V_9 = ( V_8 -> V_9 & 0x7f ) << 1 ;
if ( V_8 -> V_10 & V_11 )
V_9 |= 1 ;
return V_9 ;
}
static void F_4 ( struct V_1 * V_2 , T_1 V_12 )
{
F_2 ( V_12 , V_2 -> V_5 + V_13 ) ;
}
static void F_5 ( struct V_1 * V_2 , T_1 V_14 )
{
F_4 ( V_2 , V_14 ) ;
F_1 ( V_2 , V_15 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_2 -> V_8 -> V_16 [ V_2 -> V_17 ++ ] ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
bool V_18 = ( V_2 -> V_17 + 1 == V_2 -> V_8 -> V_19 ) ;
F_1 ( V_2 , V_18 ? V_20 : V_21 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
V_2 -> V_22 = V_23 ;
if ( V_2 -> V_18 )
F_1 ( V_2 , V_24 ) ;
else
F_9 ( & V_2 -> V_25 ) ;
}
static T_1 F_10 ( struct V_1 * V_2 )
{
return F_11 ( V_2 -> V_5 + V_13 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
V_2 -> V_8 -> V_16 [ V_2 -> V_17 ++ ] = F_10 ( V_2 ) ;
F_7 ( V_2 ) ;
}
static void F_13 ( struct V_1 * V_2 , int V_26 )
{
if ( V_26 )
F_2 ( 1 , V_2 -> V_5 + V_27 ) ;
F_2 ( ! ! V_26 , V_2 -> V_5 + V_28 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
T_1 V_3 = F_11 ( V_2 -> V_5 + V_6 ) ;
return F_15 ( V_3 ) ;
}
static void F_16 ( struct V_1 * V_2 , int V_29 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
if ( ! ( V_8 -> V_10 & V_30 ) ) {
V_2 -> V_22 = V_31 ;
F_1 ( V_2 , V_29 ? V_32 : V_33 ) ;
} else if ( V_8 -> V_10 & V_11 ) {
V_2 -> V_22 = V_34 ;
F_7 ( V_2 ) ;
} else {
V_2 -> V_22 = V_35 ;
F_6 ( V_2 ) ;
}
}
static T_2 F_17 ( int V_36 , void * V_37 )
{
struct V_1 * V_2 = V_37 ;
int V_38 = F_14 ( V_2 ) ;
unsigned long V_10 ;
T_1 V_39 ;
F_2 ( 1 , V_2 -> V_5 + V_27 ) ;
F_18 ( & V_2 -> V_40 , V_10 ) ;
if ( V_38 == V_41
|| V_38 == V_42 ) {
V_2 -> error = - V_43 ;
F_9 ( & V_2 -> V_25 ) ;
goto V_44;
}
switch ( V_2 -> V_22 ) {
case V_31 :
V_39 = F_3 ( V_2 -> V_8 ) ;
F_5 ( V_2 , V_39 ) ;
V_2 -> V_22 = V_45 ;
break;
case V_45 :
if ( V_2 -> V_8 -> V_10 & V_11 ) {
F_7 ( V_2 ) ;
V_2 -> V_22 = V_34 ;
break;
}
V_2 -> V_22 = V_35 ;
case V_35 :
if ( V_2 -> V_17 < V_2 -> V_8 -> V_19 )
F_6 ( V_2 ) ;
else
F_8 ( V_2 ) ;
break;
case V_34 :
if ( V_2 -> V_17 < V_2 -> V_8 -> V_19 )
F_12 ( V_2 ) ;
else
F_8 ( V_2 ) ;
break;
case V_23 :
V_2 -> V_22 = V_46 ;
F_9 ( & V_2 -> V_25 ) ;
break;
}
V_44:
F_19 ( & V_2 -> V_40 , V_10 ) ;
return V_47 ;
}
static int F_20 ( struct V_1 * V_2 , struct V_7 * V_8 , int V_29 ,
int V_18 )
{
unsigned long V_48 = F_21 ( V_49 ) ;
unsigned long V_10 ;
F_18 ( & V_2 -> V_40 , V_10 ) ;
V_2 -> V_8 = V_8 ;
V_2 -> V_17 = 0 ;
V_2 -> V_18 = V_18 ;
V_2 -> error = 0 ;
F_22 ( & V_2 -> V_25 ) ;
F_13 ( V_2 , 1 ) ;
F_16 ( V_2 , V_29 ) ;
F_19 ( & V_2 -> V_40 , V_10 ) ;
V_48 = F_23 ( & V_2 -> V_25 , V_48 ) ;
F_13 ( V_2 , 0 ) ;
if ( V_48 == 0 ) {
V_2 -> V_22 = V_46 ;
return - V_50 ;
}
if ( V_2 -> error )
return V_2 -> error ;
return 0 ;
}
static int F_24 ( struct V_51 * V_52 , struct V_7 * V_53 , int V_54 )
{
struct V_1 * V_2 = V_52 -> V_55 ;
int V_56 , V_57 ;
for ( V_56 = 0 ; V_56 < V_54 ; V_56 ++ ) {
V_57 = F_20 ( V_2 , & V_53 [ V_56 ] , V_56 == 0 , V_56 == V_54 - 1 ) ;
if ( V_57 )
return V_57 ;
}
return V_54 ;
}
static int F_25 ( struct V_1 * V_2 )
{
unsigned long V_58 = F_26 ( V_2 -> V_59 ) ;
unsigned int V_60 ;
F_2 ( V_61 , V_2 -> V_5 + V_62 ) ;
F_27 ( 100 ) ;
F_2 ( 0 , V_2 -> V_5 + V_62 ) ;
F_27 ( 100 ) ;
V_60 = F_28 ( V_58 , 64 * V_2 -> V_63 ) ;
if ( V_60 < 1 || V_60 > 0xff ) {
F_29 ( V_2 -> V_64 , L_1 ,
V_2 -> V_63 ) ;
return - V_65 ;
}
F_2 ( V_60 - 1 , V_2 -> V_5 + V_66 ) ;
return 0 ;
}
static T_3 F_30 ( struct V_51 * V_52 )
{
return V_67 | V_68 | V_69 ;
}
static int F_31 ( struct V_70 * V_71 )
{
struct V_72 * V_73 = V_71 -> V_64 . V_74 ;
struct V_1 * V_2 ;
struct V_75 * V_76 ;
int V_57 = 0 , V_36 ;
V_2 = F_32 ( & V_71 -> V_64 , sizeof( struct V_1 ) , V_77 ) ;
if ( ! V_2 )
return - V_78 ;
if ( F_33 ( V_71 -> V_64 . V_74 , L_2 ,
& V_2 -> V_63 ) )
V_2 -> V_63 = V_79 ;
V_2 -> V_64 = & V_71 -> V_64 ;
F_34 ( V_71 , V_2 ) ;
F_35 ( & V_2 -> V_40 ) ;
F_36 ( & V_2 -> V_25 ) ;
V_2 -> V_59 = F_37 ( & V_71 -> V_64 , NULL ) ;
if ( F_38 ( V_2 -> V_59 ) )
return F_39 ( V_2 -> V_59 ) ;
V_76 = F_40 ( V_71 , V_80 , 0 ) ;
V_2 -> V_5 = F_41 ( & V_71 -> V_64 , V_76 ) ;
if ( F_38 ( V_2 -> V_5 ) )
return F_39 ( V_2 -> V_5 ) ;
V_36 = F_42 ( V_71 , 0 ) ;
if ( V_36 < 0 )
return V_36 ;
V_57 = F_43 ( & V_71 -> V_64 , V_36 , F_17 , 0 ,
F_44 ( & V_71 -> V_64 ) , V_2 ) ;
if ( V_57 < 0 )
return V_57 ;
F_45 ( V_2 -> V_52 . V_81 , L_3 ,
sizeof( V_2 -> V_52 . V_81 ) ) ;
V_2 -> V_52 . V_82 = V_83 ;
V_2 -> V_52 . V_84 = & V_85 ;
V_2 -> V_52 . V_64 . V_86 = & V_71 -> V_64 ;
V_2 -> V_52 . V_64 . V_74 = V_73 ;
V_2 -> V_52 . V_55 = V_2 ;
V_57 = F_25 ( V_2 ) ;
if ( V_57 )
return V_57 ;
V_57 = F_46 ( V_2 -> V_59 ) ;
if ( V_57 < 0 )
return V_57 ;
V_57 = F_47 ( & V_2 -> V_52 ) ;
if ( V_57 < 0 ) {
F_48 ( V_2 -> V_59 ) ;
return V_57 ;
}
return 0 ;
}
static int F_49 ( struct V_70 * V_71 )
{
struct V_1 * V_2 = F_50 ( V_71 ) ;
F_51 ( & V_2 -> V_52 ) ;
F_48 ( V_2 -> V_59 ) ;
return 0 ;
}
