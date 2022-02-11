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
enum V_7 V_8 )
{
switch ( V_8 ) {
case V_27 :
return V_12 -> V_28 ;
case V_29 :
return V_12 -> V_30 ;
case V_31 :
case V_32 :
return V_12 -> V_33 ;
case V_34 ... V_35 - 1 :
default:
return V_12 -> V_36 ;
}
}
static void F_7 ( struct V_11 * V_12 ,
enum V_7 V_8 ,
enum V_26 V_37 )
{
switch ( V_8 ) {
case V_27 :
V_12 -> V_28 = V_37 ;
break;
case V_29 :
V_12 -> V_30 = V_37 ;
break;
case V_31 :
case V_32 :
V_12 -> V_33 = V_37 ;
break;
case V_34 ... V_35 - 1 :
default:
V_12 -> V_36 = V_37 ;
break;
}
}
static void F_8 ( struct V_11 * V_12 ,
enum V_7 V_8 )
{
switch ( V_8 ) {
case V_27 :
V_12 -> V_38 |= ( V_39 | V_40 ) ;
break;
case V_29 :
V_12 -> V_38 |= ( V_41 | V_40 ) ;
break;
case V_31 :
case V_32 :
V_12 -> V_38 |= ( V_42 | V_40 ) ;
break;
case V_34 ... V_35 - 1 :
default:
V_12 -> V_38 |= ( V_43 | V_40 ) ;
break;
}
}
enum V_44 F_9 ( struct V_45 * V_46 ,
int V_47 )
{
struct V_48 * V_49 ;
if ( ! V_46 || V_47 < 2 )
return V_50 ;
switch ( V_46 -> type ) {
case V_51 :
V_49 = ( F_10 ( V_49 ) ) V_46 ;
if ( V_49 -> V_52 != 2 || V_47 <= sizeof( * V_49 ) )
return V_50 ;
return V_49 -> V_44 ;
break;
case V_22 :
return V_46 -> V_53 [ 0 ] ;
break;
case V_20 :
if ( V_47 == 21 ) {
unsigned int V_54 = 0 ;
if ( ! memcmp ( & V_46 -> V_53 [ 16 ] , & V_54 , 4 ) )
return V_55 ;
else
return V_17 ;
} else if ( V_47 == 17 )
return V_55 ;
break;
}
return V_50 ;
}
int F_11 ( struct V_10 * V_10 ,
struct V_45 * * V_46 )
{
struct V_5 * V_5 = F_12 ( V_10 ) ;
if ( ! V_5 -> V_56 -> V_57 )
return 0 ;
return F_13 ( V_10 , V_23 , ( char * * ) V_46 ,
0 , V_58 ) ;
}
int F_14 ( enum V_7 V_8 ,
struct V_11 * V_12 ,
struct V_59 * V_59 , const unsigned char * V_60 ,
struct V_45 * V_46 ,
int V_47 , int V_61 )
{
static const char V_62 [] = L_4 ;
char * V_63 = L_5 ;
struct V_10 * V_10 = V_59 -> V_64 . V_10 ;
struct V_5 * V_5 = F_12 ( V_10 ) ;
enum V_26 V_37 = V_65 ;
int V_13 = V_47 , V_66 = 0 ;
if ( ! V_5 -> V_56 -> V_57 )
return V_65 ;
if ( V_13 <= 0 ) {
if ( V_13 && V_13 != - V_67 )
goto V_68;
V_63 = L_6 ;
V_37 = V_69 ;
if ( V_61 & V_70 ) {
V_12 -> V_38 |= V_71 ;
V_37 = V_72 ;
}
goto V_68;
}
V_37 = F_15 ( V_10 , V_23 , V_46 , V_13 , V_12 ) ;
if ( ( V_37 != V_72 ) && ( V_37 != V_65 ) ) {
if ( ( V_37 == V_69 )
|| ( V_37 == V_73 ) )
V_63 = L_7 ;
else if ( V_37 == V_74 )
V_63 = L_8 ;
goto V_68;
}
switch ( V_46 -> type ) {
case V_22 :
V_66 = 1 ;
case V_20 :
if ( V_12 -> V_38 & V_75 ) {
V_63 = L_9 ;
V_37 = V_74 ;
break;
}
if ( V_47 - sizeof( V_46 -> type ) - V_66 >=
V_12 -> V_16 -> V_25 )
V_13 = memcmp ( & V_46 -> V_53 [ V_66 ] ,
V_12 -> V_16 -> V_53 ,
V_12 -> V_16 -> V_25 ) ;
else
V_13 = - V_76 ;
if ( V_13 ) {
V_63 = L_10 ;
V_37 = V_74 ;
break;
}
V_37 = V_72 ;
break;
case V_51 :
V_12 -> V_38 |= V_77 ;
V_13 = F_16 ( V_78 ,
( const char * ) V_46 , V_13 ,
V_12 -> V_16 -> V_53 ,
V_12 -> V_16 -> V_25 ) ;
if ( V_13 == - V_79 ) {
V_37 = V_65 ;
} else if ( V_13 ) {
V_63 = L_11 ;
V_37 = V_74 ;
} else {
V_37 = V_72 ;
}
break;
default:
V_37 = V_65 ;
V_63 = L_12 ;
break;
}
V_68:
if ( V_37 != V_72 ) {
if ( ( V_2 & V_4 ) &&
( ! V_46 ||
V_46 -> type != V_51 ) ) {
if ( ! F_4 ( V_10 , V_12 ) )
V_37 = V_72 ;
}
F_17 ( V_80 , V_5 , V_60 ,
V_62 , V_63 , V_13 , 0 ) ;
} else {
F_8 ( V_12 , V_8 ) ;
}
F_7 ( V_12 , V_8 , V_37 ) ;
return V_37 ;
}
void F_18 ( struct V_11 * V_12 , struct V_59 * V_59 )
{
struct V_10 * V_10 = V_59 -> V_64 . V_10 ;
int V_13 = 0 ;
if ( V_12 -> V_38 & V_77 )
return;
V_13 = F_19 ( V_12 , V_59 , NULL , 0 , V_50 ) ;
if ( V_13 < 0 )
return;
F_4 ( V_10 , V_12 ) ;
}
void F_20 ( struct V_10 * V_10 )
{
struct V_5 * V_5 = F_12 ( V_10 ) ;
struct V_11 * V_12 ;
int V_81 , V_13 ;
if ( ! ( V_82 & V_9 ) || ! F_21 ( V_5 -> V_83 )
|| ! V_5 -> V_56 -> V_84 )
return;
V_81 = F_2 ( V_5 , V_85 , V_32 ) ;
V_12 = F_22 ( V_5 ) ;
if ( V_12 ) {
V_12 -> V_38 &= ~ ( V_9 | V_40 |
V_86 | V_87 |
V_88 ) ;
if ( V_81 )
V_12 -> V_38 |= V_9 ;
}
if ( ! V_81 )
V_13 = V_5 -> V_56 -> V_84 ( V_10 , V_23 ) ;
return;
}
static int F_23 ( struct V_10 * V_10 , const char * V_89 ,
const void * V_46 , T_3 V_90 )
{
if ( strcmp ( V_89 , V_23 ) == 0 ) {
if ( ! F_24 ( V_91 ) )
return - V_92 ;
return 1 ;
}
return 0 ;
}
static void F_25 ( struct V_5 * V_5 , int V_93 )
{
struct V_11 * V_12 ;
if ( ! ( V_82 & V_9 ) || ! F_21 ( V_5 -> V_83 ) )
return;
V_12 = F_22 ( V_5 ) ;
if ( ! V_12 )
return;
V_12 -> V_38 &= ~ V_94 ;
if ( V_93 )
V_12 -> V_38 |= V_77 ;
return;
}
int F_26 ( struct V_10 * V_10 , const char * V_89 ,
const void * V_46 , T_3 V_90 )
{
const struct V_45 * V_95 = V_46 ;
int V_96 ;
V_96 = F_23 ( V_10 , V_89 , V_46 ,
V_90 ) ;
if ( V_96 == 1 ) {
bool V_93 ;
if ( ! V_90 || ( V_95 -> type >= V_97 ) )
return - V_76 ;
V_93 = ( V_95 -> type == V_51 ) ;
if ( ! V_93 && ( V_2 & V_98 ) )
return - V_92 ;
F_25 ( F_12 ( V_10 ) , V_93 ) ;
V_96 = 0 ;
}
return V_96 ;
}
int F_27 ( struct V_10 * V_10 , const char * V_89 )
{
int V_96 ;
V_96 = F_23 ( V_10 , V_89 , NULL , 0 ) ;
if ( V_96 == 1 ) {
F_25 ( F_12 ( V_10 ) , 0 ) ;
V_96 = 0 ;
}
return V_96 ;
}
