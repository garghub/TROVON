static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
unsigned char V_4 ;
if ( F_2 ( V_2 -> V_5 ) ) {
V_2 -> V_6 = V_7 ;
return 0 ;
}
V_3 = F_3 ( V_2 -> V_5 , 0 , 0 ,
F_4 ( V_2 -> V_8 ) + V_9 , 0 , & V_4 ) ;
if ( V_3 )
goto V_10;
V_4 &= 0x0f ;
if ( V_4 == 0x0f ) {
V_3 = F_3 ( V_2 -> V_5 , 0 , 0 ,
F_4 ( V_2 -> V_8 ) + V_11 , 0 , & V_4 ) ;
if ( V_3 )
goto V_10;
}
V_2 -> V_6 = V_4 ;
V_10:
return V_3 ;
}
static int F_5 ( struct V_12 * V_5 , unsigned int V_13 )
{
int V_3 ;
struct V_1 * V_2 ;
F_6 ( V_13 > V_14 ) ;
V_2 = F_7 ( V_5 ) ;
if ( F_8 ( V_2 ) )
return F_9 ( V_2 ) ;
V_2 -> V_8 = V_13 ;
if ( ! ( V_5 -> V_15 & V_16 ) ) {
V_3 = F_1 ( V_2 ) ;
if ( V_3 )
goto V_17;
V_3 = F_10 ( V_2 ) ;
if ( V_3 )
goto V_17;
} else {
V_2 -> V_18 = V_2 -> V_5 -> V_19 . V_18 ;
V_2 -> V_20 = V_2 -> V_5 -> V_19 . V_20 ;
V_2 -> V_21 = V_2 -> V_5 -> V_19 . V_22 ;
}
V_5 -> V_1 [ V_13 - 1 ] = V_2 ;
return 0 ;
V_17:
F_11 ( V_2 ) ;
return V_3 ;
}
static int F_12 ( struct V_12 * V_5 )
{
int V_3 ;
int V_23 ;
unsigned char V_4 ;
memset ( & V_5 -> V_24 , 0 , sizeof( struct V_25 ) ) ;
V_3 = F_3 ( V_5 , 0 , 0 , V_26 , 0 , & V_4 ) ;
if ( V_3 )
goto V_10;
V_23 = V_4 & 0x0f ;
if ( V_23 > V_27 ) {
F_13 ( V_28 L_1 ,
F_14 ( V_5 -> V_29 ) , V_23 ) ;
return - V_30 ;
}
V_5 -> V_24 . V_31 = ( V_4 & 0xf0 ) >> 4 ;
V_3 = F_3 ( V_5 , 0 , 0 , V_32 , 0 , & V_4 ) ;
if ( V_3 )
goto V_10;
if ( V_4 & V_33 )
V_5 -> V_24 . V_34 = 1 ;
if ( V_4 & V_35 )
V_5 -> V_24 . V_36 = 1 ;
if ( V_4 & V_37 )
V_5 -> V_24 . V_38 = 1 ;
if ( V_23 >= V_39 ) {
V_3 = F_3 ( V_5 , 0 , 0 , V_40 , 0 , & V_4 ) ;
if ( V_3 )
goto V_10;
if ( V_4 & V_41 )
V_5 -> V_24 . V_42 = 1 ;
}
if ( V_23 >= V_27 ) {
V_3 = F_3 ( V_5 , 0 , 0 , V_43 , 0 , & V_4 ) ;
if ( V_3 )
goto V_10;
if ( V_4 & V_44 )
V_5 -> V_24 . V_45 = 1 ;
}
V_10:
return V_3 ;
}
static int F_15 ( struct V_12 * V_5 )
{
int V_3 ;
T_1 V_46 ;
if ( ! ( V_5 -> V_29 -> V_47 & V_48 ) )
return 0 ;
if ( V_5 -> V_24 . V_36 && ! V_5 -> V_24 . V_38 )
return 0 ;
V_3 = F_3 ( V_5 , 0 , 0 , V_49 , 0 , & V_46 ) ;
if ( V_3 )
return V_3 ;
V_46 |= V_50 ;
V_3 = F_3 ( V_5 , 1 , 0 , V_49 , V_46 , NULL ) ;
if ( V_3 )
return V_3 ;
return 1 ;
}
static int F_16 ( struct V_12 * V_5 )
{
int V_3 ;
T_1 V_46 ;
if ( ! F_17 ( V_5 ) )
return 0 ;
V_3 = F_3 ( V_5 , 0 , 0 , V_49 , 0 , & V_46 ) ;
if ( V_3 )
return V_3 ;
V_46 |= V_51 ;
return F_3 ( V_5 , 1 , 0 , V_49 , V_46 , NULL ) ;
}
static int F_18 ( struct V_12 * V_5 )
{
int V_3 ;
T_1 V_46 ;
if ( ! ( V_5 -> V_29 -> V_47 & V_48 ) )
return 0 ;
if ( V_5 -> V_24 . V_36 && ! V_5 -> V_24 . V_38 )
return 0 ;
V_3 = F_3 ( V_5 , 0 , 0 , V_49 , 0 , & V_46 ) ;
if ( V_3 )
return V_3 ;
if ( ! ( V_46 & V_50 ) )
return 0 ;
V_46 &= ~ V_50 ;
V_46 |= V_52 ;
V_3 = F_3 ( V_5 , 1 , 0 , V_49 , V_46 , NULL ) ;
if ( V_3 )
return V_3 ;
F_19 ( V_5 -> V_29 , V_53 ) ;
return 0 ;
}
static int F_20 ( struct V_12 * V_5 )
{
int V_54 ;
if ( V_5 -> type == V_55 )
return F_15 ( V_5 ) ;
if ( ( V_5 -> V_29 -> V_47 & V_48 ) &&
( V_5 -> V_56 . V_57 & V_58 ) ) {
V_54 = F_21 ( V_5 , V_59 ) ;
if ( V_54 )
return V_54 ;
} else
return 0 ;
V_54 = F_15 ( V_5 ) ;
if ( V_54 <= 0 )
F_21 ( V_5 , V_53 ) ;
return V_54 ;
}
static int F_22 ( struct V_12 * V_5 , int V_60 )
{
int V_3 ;
T_1 V_61 ;
if ( ! ( V_5 -> V_29 -> V_47 & V_62 ) )
return 0 ;
if ( ! V_5 -> V_24 . V_45 )
return 0 ;
V_3 = F_3 ( V_5 , 0 , 0 , V_43 , 0 , & V_61 ) ;
if ( V_3 )
return V_3 ;
if ( V_60 )
V_61 |= V_63 ;
else
V_61 &= ~ V_63 ;
V_3 = F_3 ( V_5 , 1 , 0 , V_43 , V_61 , NULL ) ;
if ( V_3 )
return V_3 ;
return 1 ;
}
static int F_23 ( struct V_12 * V_5 )
{
int V_3 ;
V_3 = F_22 ( V_5 , true ) ;
if ( V_3 <= 0 || V_5 -> type == V_55 )
return V_3 ;
V_3 = F_24 ( V_5 ) ;
if ( V_3 <= 0 )
F_22 ( V_5 , false ) ;
return V_3 ;
}
static unsigned F_25 ( struct V_12 * V_5 )
{
unsigned V_64 ;
if ( F_26 ( V_5 ) ) {
V_64 = 50000000 ;
} else {
V_64 = V_5 -> V_19 . V_64 ;
}
if ( V_5 -> type == V_65 )
V_64 = F_27 ( V_64 , F_28 ( V_5 ) ) ;
return V_64 ;
}
static int F_29 ( struct V_66 * V_29 , T_2 V_67 ,
struct V_12 * V_68 , int V_69 )
{
struct V_12 * V_5 ;
int V_54 ;
F_6 ( ! V_29 ) ;
F_30 ( ! V_29 -> V_70 ) ;
if ( ! V_69 ) {
V_54 = F_31 ( V_29 , V_29 -> V_67 , & V_67 ) ;
if ( V_54 )
goto V_54;
}
if ( F_32 ( V_29 ) ) {
V_54 = F_33 ( V_29 , V_71 ) ;
if ( V_54 )
goto V_54;
}
V_5 = F_34 ( V_29 , NULL ) ;
if ( F_8 ( V_5 ) ) {
V_54 = F_9 ( V_5 ) ;
goto V_54;
}
if ( ( V_67 & V_72 ) &&
F_35 ( V_29 , V_29 -> V_67 & V_67 , V_5 -> V_73 , NULL ) == 0 ) {
V_5 -> type = V_65 ;
if ( V_68 && ( V_68 -> type != V_65 ||
memcmp ( V_5 -> V_73 , V_68 -> V_73 , sizeof( V_5 -> V_73 ) ) != 0 ) ) {
F_36 ( V_5 ) ;
return - V_74 ;
}
} else {
V_5 -> type = V_55 ;
if ( V_68 && V_68 -> type != V_55 ) {
F_36 ( V_5 ) ;
return - V_74 ;
}
}
if ( V_29 -> V_75 -> V_76 )
V_29 -> V_75 -> V_76 ( V_29 , V_5 ) ;
if ( ! V_69 && ! F_32 ( V_29 ) ) {
V_54 = F_37 ( V_29 , & V_5 -> V_77 ) ;
if ( V_54 )
goto remove;
if ( V_68 )
V_68 -> V_77 = V_5 -> V_77 ;
F_38 ( V_29 , V_78 ) ;
}
if ( ! V_68 && V_5 -> type == V_65 ) {
V_54 = F_39 ( V_29 , V_5 ) ;
if ( V_54 )
return V_54 ;
F_40 ( V_5 ) ;
}
if ( ! V_69 && ! F_32 ( V_29 ) ) {
V_54 = F_41 ( V_5 ) ;
if ( V_54 )
goto remove;
}
if ( V_5 -> V_15 & V_16 ) {
F_42 ( V_29 , V_5 -> V_19 . V_64 ) ;
if ( V_5 -> V_24 . V_45 ) {
F_43 ( V_5 ) ;
F_44 ( V_5 -> V_29 , V_79 ) ;
}
goto V_80;
}
V_54 = F_12 ( V_5 ) ;
if ( V_54 )
goto remove;
V_54 = F_45 ( V_5 ) ;
if ( V_54 )
goto remove;
if ( V_68 ) {
int V_81 = ( V_5 -> V_19 . V_18 == V_68 -> V_19 . V_18 &&
V_5 -> V_19 . V_20 == V_68 -> V_19 . V_20 ) ;
F_36 ( V_5 ) ;
if ( ! V_81 )
return - V_74 ;
V_5 = V_68 ;
}
F_46 ( V_5 , NULL ) ;
if ( V_5 -> type == V_65 ) {
V_54 = F_47 ( V_29 , V_5 , V_68 != NULL ) ;
if ( V_54 ) {
F_48 ( V_29 ) ;
if ( F_32 ( V_29 ) )
F_33 ( V_29 , V_71 ) ;
V_5 -> type = V_55 ;
} else
V_5 -> V_82 . type = & V_83 ;
}
V_54 = F_16 ( V_5 ) ;
if ( V_54 )
goto remove;
V_54 = F_23 ( V_5 ) ;
if ( V_54 > 0 )
F_49 ( V_5 ) ;
else if ( V_54 )
goto remove;
F_42 ( V_29 , F_25 ( V_5 ) ) ;
V_54 = F_20 ( V_5 ) ;
if ( V_54 > 0 )
F_19 ( V_5 -> V_29 , V_59 ) ;
else if ( V_54 )
goto remove;
V_80:
if ( ! V_68 )
V_29 -> V_5 = V_5 ;
return 0 ;
remove:
if ( ! V_68 )
F_36 ( V_5 ) ;
V_54:
return V_54 ;
}
static void F_50 ( struct V_66 * V_29 )
{
int V_84 ;
F_6 ( ! V_29 ) ;
F_6 ( ! V_29 -> V_5 ) ;
for ( V_84 = 0 ; V_84 < V_29 -> V_5 -> V_85 ; V_84 ++ ) {
if ( V_29 -> V_5 -> V_1 [ V_84 ] ) {
F_11 ( V_29 -> V_5 -> V_1 [ V_84 ] ) ;
V_29 -> V_5 -> V_1 [ V_84 ] = NULL ;
}
}
F_36 ( V_29 -> V_5 ) ;
V_29 -> V_5 = NULL ;
}
static void F_51 ( struct V_66 * V_29 )
{
int V_54 ;
F_6 ( ! V_29 ) ;
F_6 ( ! V_29 -> V_5 ) ;
if ( V_29 -> V_47 & V_86 ) {
V_54 = F_52 ( & V_29 -> V_5 -> V_82 ) ;
if ( V_54 < 0 )
goto V_10;
}
F_53 ( V_29 ) ;
V_54 = F_41 ( V_29 -> V_5 ) ;
F_54 ( V_29 ) ;
if ( V_29 -> V_47 & V_86 )
F_55 ( & V_29 -> V_5 -> V_82 ) ;
V_10:
if ( V_54 ) {
F_50 ( V_29 ) ;
F_53 ( V_29 ) ;
F_56 ( V_29 ) ;
F_54 ( V_29 ) ;
}
}
static int F_57 ( struct V_66 * V_29 )
{
int V_84 , V_54 = 0 ;
for ( V_84 = 0 ; V_84 < V_29 -> V_5 -> V_85 ; V_84 ++ ) {
struct V_1 * V_2 = V_29 -> V_5 -> V_1 [ V_84 ] ;
if ( V_2 && F_58 ( V_2 ) && V_2 -> V_82 . V_87 ) {
const struct V_88 * V_89 = V_2 -> V_82 . V_87 -> V_90 ;
if ( ! V_89 || ! V_89 -> V_91 || ! V_89 -> V_92 ) {
V_54 = - V_93 ;
} else
V_54 = V_89 -> V_91 ( & V_2 -> V_82 ) ;
if ( V_54 )
break;
}
}
while ( V_54 && -- V_84 >= 0 ) {
struct V_1 * V_2 = V_29 -> V_5 -> V_1 [ V_84 ] ;
if ( V_2 && F_58 ( V_2 ) && V_2 -> V_82 . V_87 ) {
const struct V_88 * V_89 = V_2 -> V_82 . V_87 -> V_90 ;
V_89 -> V_92 ( & V_2 -> V_82 ) ;
}
}
if ( ! V_54 && F_59 ( V_29 ) && F_60 ( V_29 ) ) {
F_53 ( V_29 ) ;
F_18 ( V_29 -> V_5 ) ;
F_54 ( V_29 ) ;
}
return V_54 ;
}
static int F_61 ( struct V_66 * V_29 )
{
int V_84 , V_54 = 0 ;
F_6 ( ! V_29 ) ;
F_6 ( ! V_29 -> V_5 ) ;
F_53 ( V_29 ) ;
if ( F_62 ( V_29 ) || ! F_59 ( V_29 ) )
V_54 = F_29 ( V_29 , V_29 -> V_67 , V_29 -> V_5 ,
F_59 ( V_29 ) ) ;
else if ( F_59 ( V_29 ) && F_60 ( V_29 ) ) {
V_54 = F_20 ( V_29 -> V_5 ) ;
if ( V_54 > 0 ) {
F_19 ( V_29 , V_59 ) ;
V_54 = 0 ;
}
}
if ( ! V_54 && V_29 -> V_94 )
F_63 ( V_29 ) ;
F_54 ( V_29 ) ;
for ( V_84 = 0 ; ! V_54 && V_84 < V_29 -> V_5 -> V_85 ; V_84 ++ ) {
struct V_1 * V_2 = V_29 -> V_5 -> V_1 [ V_84 ] ;
if ( V_2 && F_58 ( V_2 ) && V_2 -> V_82 . V_87 ) {
const struct V_88 * V_89 = V_2 -> V_82 . V_87 -> V_90 ;
V_54 = V_89 -> V_92 ( & V_2 -> V_82 ) ;
}
}
return V_54 ;
}
static int F_64 ( struct V_66 * V_29 )
{
int V_3 ;
T_2 V_67 ;
F_6 ( ! V_29 ) ;
F_6 ( ! V_29 -> V_5 ) ;
F_53 ( V_29 ) ;
F_65 ( V_29 ) ;
F_48 ( V_29 ) ;
F_66 ( V_29 , V_29 -> V_95 ) ;
V_3 = F_31 ( V_29 , 0 , & V_67 ) ;
if ( V_3 )
goto V_10;
if ( V_29 -> V_96 )
V_29 -> V_95 = V_29 -> V_96 ;
V_29 -> V_67 = F_67 ( V_29 , V_67 & ~ 0x7F ) ;
if ( ! V_29 -> V_67 ) {
V_3 = - V_30 ;
goto V_10;
}
V_3 = F_29 ( V_29 , V_29 -> V_67 , V_29 -> V_5 ,
F_59 ( V_29 ) ) ;
if ( ! V_3 && V_29 -> V_94 )
F_63 ( V_29 ) ;
V_10:
F_54 ( V_29 ) ;
return V_3 ;
}
int F_68 ( struct V_66 * V_29 )
{
int V_54 , V_84 , V_97 ;
T_2 V_67 ;
struct V_12 * V_5 ;
F_6 ( ! V_29 ) ;
F_30 ( ! V_29 -> V_70 ) ;
V_54 = F_31 ( V_29 , 0 , & V_67 ) ;
if ( V_54 )
return V_54 ;
F_69 ( V_29 , & V_98 ) ;
if ( V_29 -> V_96 )
V_29 -> V_95 = V_29 -> V_96 ;
if ( V_67 & 0x7F ) {
F_13 ( V_99 L_2
L_3 ,
F_14 ( V_29 ) ) ;
V_67 &= ~ 0x7F ;
}
V_29 -> V_67 = F_67 ( V_29 , V_67 ) ;
if ( ! V_29 -> V_67 ) {
V_54 = - V_30 ;
goto V_54;
}
V_54 = F_29 ( V_29 , V_29 -> V_67 , NULL , 0 ) ;
if ( V_54 )
goto V_54;
V_5 = V_29 -> V_5 ;
if ( V_29 -> V_47 & V_86 ) {
V_54 = F_70 ( & V_5 -> V_82 ) ;
if ( V_54 )
goto remove;
F_71 ( & V_5 -> V_82 ) ;
}
V_97 = ( V_67 & 0x70000000 ) >> 28 ;
V_5 -> V_85 = 0 ;
for ( V_84 = 0 ; V_84 < V_97 ; V_84 ++ , V_5 -> V_85 ++ ) {
V_54 = F_5 ( V_29 -> V_5 , V_84 + 1 ) ;
if ( V_54 )
goto remove;
if ( V_29 -> V_47 & V_86 )
F_71 ( & V_5 -> V_1 [ V_84 ] -> V_82 ) ;
}
F_54 ( V_29 ) ;
V_54 = F_72 ( V_29 -> V_5 ) ;
if ( V_54 )
goto V_100;
for ( V_84 = 0 ; V_84 < V_97 ; V_84 ++ ) {
V_54 = F_73 ( V_29 -> V_5 -> V_1 [ V_84 ] ) ;
if ( V_54 )
goto V_100;
}
F_53 ( V_29 ) ;
return 0 ;
V_100:
F_50 ( V_29 ) ;
F_53 ( V_29 ) ;
remove:
F_54 ( V_29 ) ;
if ( V_29 -> V_5 )
F_50 ( V_29 ) ;
F_53 ( V_29 ) ;
V_54:
F_56 ( V_29 ) ;
F_13 ( V_28 L_4 ,
F_14 ( V_29 ) , V_54 ) ;
return V_54 ;
}
