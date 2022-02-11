static int T_1 F_1 ( char * V_1 )
{
if ( strncmp ( V_1 , L_1 , 3 ) == 0 )
V_2 = 0 ;
else if ( strncmp ( V_1 , L_2 , 3 ) == 0 )
V_2 = V_3 ;
else if ( strncmp ( V_1 , L_3 , 3 ) == 0 )
V_2 = V_4 ;
return 1 ;
}
int F_2 ( struct V_5 * V_5 , int V_6 , enum V_7 V_8 )
{
if ( ! V_2 )
return 0 ;
return F_3 ( V_5 , V_8 , V_6 , V_9 ) ;
}
static int F_4 ( struct V_10 * V_10 ,
struct V_11 * V_12 )
{
int V_13 , V_14 ;
T_2 V_15 = V_12 -> V_16 -> V_15 ;
if ( V_15 <= V_17 ) {
V_14 = 1 ;
V_12 -> V_16 -> V_18 . V_19 . type = V_20 ;
} else {
V_14 = 0 ;
V_12 -> V_16 -> V_18 . V_21 . type = V_22 ;
V_12 -> V_16 -> V_18 . V_21 . V_15 = V_15 ;
}
V_13 = F_5 ( V_10 , V_23 ,
& V_12 -> V_16 -> V_18 . V_24 [ V_14 ] ,
( sizeof( V_12 -> V_16 -> V_18 ) - V_14 ) +
V_12 -> V_16 -> V_25 , 0 ) ;
return V_13 ;
}
enum V_26 F_6 ( struct V_11 * V_12 ,
int V_8 )
{
switch ( V_8 ) {
case V_27 :
return V_12 -> V_28 ;
case V_29 :
return V_12 -> V_30 ;
case V_31 :
return V_12 -> V_32 ;
case V_33 :
return V_12 -> V_34 ;
case V_35 :
default:
return V_12 -> V_36 ;
}
}
static void F_7 ( struct V_11 * V_12 ,
int V_8 , enum V_26 V_37 )
{
switch ( V_8 ) {
case V_27 :
V_12 -> V_28 = V_37 ;
break;
case V_29 :
V_12 -> V_30 = V_37 ;
break;
case V_31 :
V_12 -> V_32 = V_37 ;
break;
case V_33 :
V_12 -> V_34 = V_37 ;
break;
case V_35 :
default:
V_12 -> V_36 = V_37 ;
break;
}
}
static void F_8 ( struct V_11 * V_12 , int V_8 )
{
switch ( V_8 ) {
case V_27 :
V_12 -> V_38 |= ( V_39 | V_40 ) ;
break;
case V_29 :
V_12 -> V_38 |= ( V_41 | V_40 ) ;
break;
case V_31 :
V_12 -> V_38 |= ( V_42 | V_40 ) ;
break;
case V_33 :
V_12 -> V_38 |= ( V_43 | V_40 ) ;
break;
case V_35 :
default:
V_12 -> V_38 |= ( V_44 | V_40 ) ;
break;
}
}
void F_9 ( struct V_45 * V_46 , int V_47 ,
struct V_48 * V_49 )
{
struct V_50 * V_51 ;
if ( ! V_46 || V_47 < 2 )
return;
switch ( V_46 -> type ) {
case V_52 :
V_51 = ( F_10 ( V_51 ) ) V_46 ;
if ( V_51 -> V_53 != 2 || V_47 <= sizeof( * V_51 ) )
return;
V_49 -> V_15 = V_51 -> V_54 ;
break;
case V_22 :
V_49 -> V_15 = V_46 -> V_55 [ 0 ] ;
break;
case V_20 :
if ( V_47 == 21 ) {
unsigned int V_56 = 0 ;
if ( ! memcmp ( & V_46 -> V_55 [ 16 ] , & V_56 , 4 ) )
V_49 -> V_15 = V_57 ;
else
V_49 -> V_15 = V_17 ;
} else if ( V_47 == 17 )
V_49 -> V_15 = V_57 ;
break;
}
}
int F_11 ( struct V_10 * V_10 ,
struct V_45 * * V_46 )
{
struct V_5 * V_5 = F_12 ( V_10 ) ;
if ( ! V_5 -> V_58 -> V_59 )
return 0 ;
return F_13 ( V_10 , V_23 , ( char * * ) V_46 ,
0 , V_60 ) ;
}
int F_14 ( int V_8 , struct V_11 * V_12 ,
struct V_61 * V_61 , const unsigned char * V_62 ,
struct V_45 * V_46 ,
int V_47 , int V_63 )
{
static const char V_64 [] = L_4 ;
char * V_65 = L_5 ;
struct V_10 * V_10 = V_61 -> V_66 . V_10 ;
struct V_5 * V_5 = F_12 ( V_10 ) ;
enum V_26 V_37 = V_67 ;
int V_13 = V_47 , V_68 = 0 ;
if ( ! V_5 -> V_58 -> V_59 )
return V_67 ;
if ( V_13 <= 0 ) {
if ( V_13 && V_13 != - V_69 )
goto V_70;
V_65 = L_6 ;
V_37 = V_71 ;
if ( V_63 & V_72 ) {
V_12 -> V_38 |= V_73 ;
V_37 = V_74 ;
}
goto V_70;
}
V_37 = F_15 ( V_10 , V_23 , V_46 , V_13 , V_12 ) ;
if ( ( V_37 != V_74 ) && ( V_37 != V_67 ) ) {
if ( ( V_37 == V_71 )
|| ( V_37 == V_75 ) )
V_65 = L_7 ;
else if ( V_37 == V_76 )
V_65 = L_8 ;
goto V_70;
}
switch ( V_46 -> type ) {
case V_22 :
V_68 = 1 ;
case V_20 :
if ( V_12 -> V_38 & V_77 ) {
V_65 = L_9 ;
V_37 = V_76 ;
break;
}
if ( V_47 - sizeof( V_46 -> type ) - V_68 >=
V_12 -> V_16 -> V_25 )
V_13 = memcmp ( & V_46 -> V_55 [ V_68 ] ,
V_12 -> V_16 -> V_55 ,
V_12 -> V_16 -> V_25 ) ;
else
V_13 = - V_78 ;
if ( V_13 ) {
V_65 = L_10 ;
V_37 = V_76 ;
break;
}
V_37 = V_74 ;
break;
case V_52 :
V_12 -> V_38 |= V_79 ;
V_13 = F_16 ( V_80 ,
( const char * ) V_46 , V_13 ,
V_12 -> V_16 -> V_55 ,
V_12 -> V_16 -> V_25 ) ;
if ( V_13 == - V_81 ) {
V_37 = V_67 ;
} else if ( V_13 ) {
V_65 = L_11 ;
V_37 = V_76 ;
} else {
V_37 = V_74 ;
}
break;
default:
V_37 = V_67 ;
V_65 = L_12 ;
break;
}
V_70:
if ( V_37 != V_74 ) {
if ( ( V_2 & V_4 ) &&
( ! V_46 ||
V_46 -> type != V_52 ) ) {
if ( ! F_4 ( V_10 , V_12 ) )
V_37 = V_74 ;
}
F_17 ( V_82 , V_5 , V_62 ,
V_64 , V_65 , V_13 , 0 ) ;
} else {
F_8 ( V_12 , V_8 ) ;
}
F_7 ( V_12 , V_8 , V_37 ) ;
return V_37 ;
}
void F_18 ( struct V_11 * V_12 , struct V_61 * V_61 )
{
struct V_10 * V_10 = V_61 -> V_66 . V_10 ;
int V_13 = 0 ;
if ( V_12 -> V_38 & V_79 )
return;
V_13 = F_19 ( V_12 , V_61 , NULL , NULL ) ;
if ( V_13 < 0 )
return;
F_4 ( V_10 , V_12 ) ;
}
void F_20 ( struct V_10 * V_10 )
{
struct V_5 * V_5 = F_12 ( V_10 ) ;
struct V_11 * V_12 ;
int V_83 , V_13 ;
if ( ! ( V_84 & V_9 ) || ! F_21 ( V_5 -> V_85 )
|| ! V_5 -> V_58 -> V_86 )
return;
V_83 = F_2 ( V_5 , V_87 , V_88 ) ;
V_12 = F_22 ( V_5 ) ;
if ( V_12 ) {
V_12 -> V_38 &= ~ ( V_9 | V_40 |
V_89 | V_90 |
V_91 ) ;
if ( V_83 )
V_12 -> V_38 |= V_9 ;
}
if ( ! V_83 )
V_13 = V_5 -> V_58 -> V_86 ( V_10 , V_23 ) ;
return;
}
static int F_23 ( struct V_10 * V_10 , const char * V_92 ,
const void * V_46 , T_3 V_93 )
{
if ( strcmp ( V_92 , V_23 ) == 0 ) {
if ( ! F_24 ( V_94 ) )
return - V_95 ;
return 1 ;
}
return 0 ;
}
static void F_25 ( struct V_5 * V_5 , int V_96 )
{
struct V_11 * V_12 ;
if ( ! ( V_84 & V_9 ) || ! F_21 ( V_5 -> V_85 ) )
return;
V_12 = F_22 ( V_5 ) ;
if ( ! V_12 )
return;
V_12 -> V_38 &= ~ V_97 ;
if ( V_96 )
V_12 -> V_38 |= V_79 ;
return;
}
int F_26 ( struct V_10 * V_10 , const char * V_92 ,
const void * V_46 , T_3 V_93 )
{
const struct V_45 * V_98 = V_46 ;
int V_99 ;
V_99 = F_23 ( V_10 , V_92 , V_46 ,
V_93 ) ;
if ( V_99 == 1 ) {
bool V_96 ;
if ( ! V_93 || ( V_98 -> type >= V_100 ) )
return - V_78 ;
V_96 = ( V_98 -> type == V_52 ) ;
if ( ! V_96 && ( V_2 & V_101 ) )
return - V_95 ;
F_25 ( F_12 ( V_10 ) , V_96 ) ;
V_99 = 0 ;
}
return V_99 ;
}
int F_27 ( struct V_10 * V_10 , const char * V_92 )
{
int V_99 ;
V_99 = F_23 ( V_10 , V_92 , NULL , 0 ) ;
if ( V_99 == 1 ) {
F_25 ( F_12 ( V_10 ) , 0 ) ;
V_99 = 0 ;
}
return V_99 ;
}
