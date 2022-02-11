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
struct V_5 * V_5 = V_10 -> V_58 ;
if ( ! V_5 -> V_59 -> V_60 )
return 0 ;
return F_12 ( V_10 , V_23 , ( char * * ) V_46 ,
0 , V_61 ) ;
}
int F_13 ( int V_8 , struct V_11 * V_12 ,
struct V_62 * V_62 , const unsigned char * V_63 ,
struct V_45 * V_46 ,
int V_47 , int V_64 )
{
static const char V_65 [] = L_4 ;
char * V_66 = L_5 ;
struct V_10 * V_10 = V_62 -> V_67 ;
struct V_5 * V_5 = V_10 -> V_58 ;
enum V_26 V_37 = V_68 ;
int V_13 = V_47 , V_69 = 0 ;
if ( ! V_5 -> V_59 -> V_60 )
return V_68 ;
if ( V_13 <= 0 ) {
if ( V_13 && V_13 != - V_70 )
goto V_71;
V_66 = L_6 ;
V_37 = V_72 ;
if ( V_64 & V_73 ) {
V_12 -> V_38 |= V_74 ;
V_37 = V_75 ;
}
goto V_71;
}
V_37 = F_14 ( V_10 , V_23 , V_46 , V_13 , V_12 ) ;
if ( ( V_37 != V_75 ) && ( V_37 != V_68 ) ) {
if ( ( V_37 == V_72 )
|| ( V_37 == V_76 ) )
V_66 = L_7 ;
else if ( V_37 == V_77 )
V_66 = L_8 ;
goto V_71;
}
switch ( V_46 -> type ) {
case V_22 :
V_69 = 1 ;
case V_20 :
if ( V_12 -> V_38 & V_78 ) {
V_66 = L_9 ;
V_37 = V_77 ;
break;
}
if ( V_47 - sizeof( V_46 -> type ) - V_69 >=
V_12 -> V_16 -> V_25 )
V_13 = memcmp ( & V_46 -> V_55 [ V_69 ] ,
V_12 -> V_16 -> V_55 ,
V_12 -> V_16 -> V_25 ) ;
else
V_13 = - V_79 ;
if ( V_13 ) {
V_66 = L_10 ;
V_37 = V_77 ;
break;
}
V_37 = V_75 ;
break;
case V_52 :
V_12 -> V_38 |= V_80 ;
V_13 = F_15 ( V_81 ,
( const char * ) V_46 , V_13 ,
V_12 -> V_16 -> V_55 ,
V_12 -> V_16 -> V_25 ) ;
if ( V_13 == - V_82 ) {
V_37 = V_68 ;
} else if ( V_13 ) {
V_66 = L_11 ;
V_37 = V_77 ;
} else {
V_37 = V_75 ;
}
break;
default:
V_37 = V_68 ;
V_66 = L_12 ;
break;
}
V_71:
if ( V_37 != V_75 ) {
if ( ( V_2 & V_4 ) &&
( ! V_46 ||
V_46 -> type != V_52 ) ) {
if ( ! F_4 ( V_10 , V_12 ) )
V_37 = V_75 ;
}
F_16 ( V_83 , V_5 , V_63 ,
V_65 , V_66 , V_13 , 0 ) ;
} else {
F_8 ( V_12 , V_8 ) ;
}
F_7 ( V_12 , V_8 , V_37 ) ;
return V_37 ;
}
void F_17 ( struct V_11 * V_12 , struct V_62 * V_62 )
{
struct V_10 * V_10 = V_62 -> V_67 ;
int V_13 = 0 ;
if ( V_12 -> V_38 & V_80 )
return;
V_13 = F_18 ( V_12 , V_62 , NULL , NULL ) ;
if ( V_13 < 0 )
return;
F_4 ( V_10 , V_12 ) ;
}
void F_19 ( struct V_10 * V_10 )
{
struct V_5 * V_5 = V_10 -> V_58 ;
struct V_11 * V_12 ;
int V_84 , V_13 ;
if ( ! ( V_85 & V_9 ) || ! F_20 ( V_5 -> V_86 )
|| ! V_5 -> V_59 -> V_87 )
return;
V_84 = F_2 ( V_5 , V_88 , V_89 ) ;
V_12 = F_21 ( V_5 ) ;
if ( V_12 ) {
V_12 -> V_38 &= ~ ( V_9 | V_40 |
V_90 | V_91 |
V_92 ) ;
if ( V_84 )
V_12 -> V_38 |= V_9 ;
}
if ( ! V_84 )
V_13 = V_5 -> V_59 -> V_87 ( V_10 , V_23 ) ;
return;
}
static int F_22 ( struct V_10 * V_10 , const char * V_93 ,
const void * V_46 , T_3 V_94 )
{
if ( strcmp ( V_93 , V_23 ) == 0 ) {
if ( ! F_23 ( V_95 ) )
return - V_96 ;
return 1 ;
}
return 0 ;
}
static void F_24 ( struct V_5 * V_5 , int V_97 )
{
struct V_11 * V_12 ;
if ( ! ( V_85 & V_9 ) || ! F_20 ( V_5 -> V_86 ) )
return;
V_12 = F_21 ( V_5 ) ;
if ( ! V_12 )
return;
V_12 -> V_38 &= ~ V_98 ;
if ( V_97 )
V_12 -> V_38 |= V_80 ;
return;
}
int F_25 ( struct V_10 * V_10 , const char * V_93 ,
const void * V_46 , T_3 V_94 )
{
const struct V_45 * V_99 = V_46 ;
int V_100 ;
V_100 = F_22 ( V_10 , V_93 , V_46 ,
V_94 ) ;
if ( V_100 == 1 ) {
if ( ! V_94 || ( V_99 -> type >= V_101 ) )
return - V_79 ;
F_24 ( V_10 -> V_58 ,
( V_99 -> type == V_52 ) ? 1 : 0 ) ;
V_100 = 0 ;
}
return V_100 ;
}
int F_26 ( struct V_10 * V_10 , const char * V_93 )
{
int V_100 ;
V_100 = F_22 ( V_10 , V_93 , NULL , 0 ) ;
if ( V_100 == 1 ) {
F_24 ( V_10 -> V_58 , 0 ) ;
V_100 = 0 ;
}
return V_100 ;
}
