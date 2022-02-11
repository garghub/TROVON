static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned long V_8 , V_9 , V_10 ;
V_8 = F_2 ( V_6 -> V_11 + V_12 ) ;
V_9 = F_2 ( V_6 -> V_11 + V_13 ) & V_8 ;
V_10 = F_2 ( V_6 -> V_11 + V_14 ) ;
if ( F_3 ( V_10 ) ) {
F_4 ( V_15 L_1 ,
V_16 , V_10 ) ;
F_5 ( V_10 , V_6 -> V_11 + V_14 ) ;
}
if ( V_9 & ~ ( V_17 | \
V_18 ) ) {
F_4 ( V_15 L_2 ,
V_16 , V_9 ) ;
return V_19 ;
}
F_5 ( V_9 , V_6 -> V_11 + V_13 ) ;
if ( V_9 & V_17 )
F_6 ( V_4 -> V_20 ) ;
if ( V_9 & V_18 )
F_6 ( V_4 -> V_21 ) ;
return V_22 ;
}
static void
F_7 ( void T_2 * V_23 , int V_24 ,
unsigned long V_25 ,
const struct V_26 * V_27 )
{
int V_28 ;
F_5 ( 0 , V_23 + F_8 ( V_24 ) ) ;
F_5 ( 0 , V_23 + F_9 ( V_24 ) ) ;
for ( V_28 = 0 ; V_28 < V_27 -> V_29 ; V_28 ++ ) {
const struct V_30 * V_31 = V_27 -> V_31 + V_28 ;
if ( ( V_31 -> V_23 & 0xffff0000 ) < ( V_25 & 0xffff0000 ) ) {
F_5 ( V_31 -> V_23 & 0xffff0000 ,
V_23 + F_9 ( V_24 ) ) ;
F_5 ( ( ( V_31 -> V_32 - 1 ) & 0xffff0000 ) |
( V_31 -> V_33 << 8 ) |
( V_27 -> V_34 << 4 ) | 1 ,
V_23 + F_8 ( V_24 ) ) ;
}
}
}
static int F_10 ( struct V_35 * V_36 )
{
int V_37 ;
struct V_38 * V_39 = V_36 -> V_39 ;
struct V_40 * V_41 = V_36 -> V_42 ;
struct V_43 * V_44 = V_41 -> V_44 ;
struct V_45 * V_46 = V_41 -> V_46 ;
struct V_5 * V_6 ;
struct V_3 * V_4 = F_11 ( V_44 ) ;
const struct V_26 * V_27 ;
unsigned long V_47 ;
V_6 = F_12 ( V_46 , V_36 ) ;
F_13 ( V_36 , & V_48 ) ;
V_37 = F_14 ( V_39 ,
V_49 ,
V_6 -> V_50 * 2 ,
V_51 - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_15 ( V_39 , 0 ,
V_49 ,
V_6 -> V_50 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_15 ( V_36 -> V_39 , 0 ,
V_52 ,
V_6 -> V_50 ) ;
if ( V_37 < 0 )
return V_37 ;
if ( V_4 == NULL ) {
V_4 = F_16 ( sizeof( struct V_3 ) , V_53 ) ;
if ( V_4 == NULL )
return - V_54 ;
V_4 -> V_7 = V_6 ;
V_37 = F_17 ( V_6 -> V_1 , F_1 , V_55 ,
L_3 , V_4 ) ;
if ( V_37 ) {
F_18 ( V_4 ) ;
return - V_56 ;
}
F_19 ( V_44 , V_4 ) ;
F_5 ( ( unsigned long ) - 1 , V_6 -> V_11 + V_57 ) ;
}
V_27 = F_20 () ;
V_47 = V_36 -> V_58 . V_47 ;
if ( V_36 -> V_59 == V_60 ) {
V_4 -> V_20 = V_36 ;
F_7 ( V_6 -> V_11 ,
V_61 , V_47 , V_27 ) ;
} else {
V_4 -> V_21 = V_36 ;
F_7 ( V_6 -> V_11 ,
V_62 , V_47 , V_27 ) ;
}
return 0 ;
}
static int F_21 ( struct V_35 * V_36 )
{
struct V_40 * V_41 = V_36 -> V_42 ;
struct V_45 * V_46 = V_41 -> V_46 ;
struct V_43 * V_44 = V_41 -> V_44 ;
struct V_3 * V_4 = F_11 ( V_44 ) ;
struct V_5 * V_6 ;
V_6 = F_12 ( V_46 , V_36 ) ;
if ( ! V_4 || ! V_6 )
return 0 ;
if ( V_36 -> V_59 == V_60 )
V_4 -> V_20 = NULL ;
else
V_4 -> V_21 = NULL ;
if ( ! V_4 -> V_20 && ! V_4 -> V_21 ) {
F_5 ( 0 , V_6 -> V_11 + V_57 ) ;
F_22 ( V_6 -> V_1 , V_4 ) ;
F_18 ( V_4 ) ;
F_19 ( V_44 , NULL ) ;
}
return 0 ;
}
static int F_23 ( struct V_35 * V_36 ,
struct V_63 * V_64 )
{
struct V_38 * V_39 = V_36 -> V_39 ;
F_24 ( V_36 , & V_36 -> V_58 ) ;
V_39 -> V_65 = F_25 ( V_64 ) ;
return 0 ;
}
static int F_26 ( struct V_35 * V_36 )
{
F_24 ( V_36 , NULL ) ;
return 0 ;
}
static int F_27 ( struct V_35 * V_36 )
{
struct V_38 * V_39 = V_36 -> V_39 ;
struct V_40 * V_41 = V_36 -> V_42 ;
struct V_45 * V_46 = V_41 -> V_46 ;
struct V_5 * V_6 ;
unsigned long V_32 , V_66 ;
V_6 = F_12 ( V_46 , V_36 ) ;
V_32 = F_28 ( V_39 , V_39 -> V_67 ) ;
V_32 = ( V_32 >> 2 ) - 1 ;
V_66 = F_29 ( V_36 ) ;
if ( V_36 -> V_59 == V_60 ) {
F_5 ( V_66 , V_6 -> V_11 + V_68 ) ;
F_5 ( V_39 -> V_69 , V_6 -> V_11 + V_70 ) ;
F_5 ( V_32 , V_6 -> V_11 + V_71 ) ;
} else {
F_5 ( V_66 , V_6 -> V_11 + V_72 ) ;
F_5 ( V_39 -> V_69 , V_6 -> V_11 + V_73 ) ;
F_5 ( V_32 , V_6 -> V_11 + V_74 ) ;
}
return 0 ;
}
static T_3 F_30 ( struct V_35
* V_36 )
{
struct V_40 * V_41 = V_36 -> V_42 ;
struct V_45 * V_46 = V_41 -> V_46 ;
struct V_5 * V_6 ;
T_3 V_66 ;
V_6 = F_12 ( V_46 , V_36 ) ;
if ( V_36 -> V_59 == V_60 )
V_66 = F_31 ( V_36 -> V_39 ,
F_2 ( V_6 -> V_11 + V_75 ) ) ;
else
V_66 = F_31 ( V_36 -> V_39 ,
F_2 ( V_6 -> V_11 + V_76 ) ) ;
return V_66 ;
}
static int F_32 ( struct V_77 * V_78 ,
int V_59 )
{
struct V_35 * V_36 = V_78 -> V_79 [ V_59 ] . V_36 ;
struct V_80 * V_81 = & V_36 -> V_58 ;
T_4 V_32 = V_48 . V_82 ;
V_81 -> V_83 . type = V_84 ;
V_81 -> V_83 . V_83 = V_78 -> V_85 -> V_83 ;
V_81 -> V_86 = F_33 ( V_78 -> V_85 -> V_83 , V_32 ,
& V_81 -> V_47 , V_53 ) ;
if ( ! V_81 -> V_86 )
return - V_54 ;
V_81 -> V_87 = V_32 ;
V_81 -> V_42 = NULL ;
return 0 ;
}
static int F_34 ( struct V_40 * V_88 )
{
struct V_89 * V_85 = V_88 -> V_85 -> V_89 ;
struct V_77 * V_78 = V_88 -> V_78 ;
int V_90 ;
if ( ! V_85 -> V_83 -> V_91 )
V_85 -> V_83 -> V_91 = & V_92 ;
if ( ! V_85 -> V_83 -> V_93 )
V_85 -> V_83 -> V_93 = F_35 ( 32 ) ;
if ( V_78 -> V_79 [ V_60 ] . V_36 ) {
V_90 = F_32 ( V_78 ,
V_60 ) ;
if ( V_90 )
return V_90 ;
}
if ( V_78 -> V_79 [ V_94 ] . V_36 ) {
V_90 = F_32 ( V_78 ,
V_94 ) ;
if ( V_90 )
return V_90 ;
}
return 0 ;
}
static void F_36 ( struct V_77 * V_78 )
{
struct V_35 * V_36 ;
struct V_80 * V_81 ;
int V_59 ;
for ( V_59 = 0 ; V_59 < 2 ; V_59 ++ ) {
V_36 = V_78 -> V_79 [ V_59 ] . V_36 ;
if ( ! V_36 )
continue;
V_81 = & V_36 -> V_58 ;
if ( ! V_81 -> V_86 )
continue;
F_37 ( V_78 -> V_85 -> V_83 , V_81 -> V_87 ,
V_81 -> V_86 , V_81 -> V_47 ) ;
V_81 -> V_86 = NULL ;
}
}
static int F_38 ( struct V_95 * V_96 )
{
return F_39 ( & V_96 -> V_83 , & V_97 ) ;
}
static int F_40 ( struct V_95 * V_96 )
{
F_41 ( & V_96 -> V_83 ) ;
return 0 ;
}
