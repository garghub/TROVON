static int T_1 F_1 ( char * V_1 )
{
if ( strncmp ( V_1 , L_1 , 3 ) == 0 )
V_2 = 0 ;
else if ( strncmp ( V_1 , L_2 , 3 ) == 0 )
V_2 = V_3 ;
return 1 ;
}
int F_2 ( struct V_4 * V_4 , int V_5 , enum V_6 V_7 )
{
if ( ! V_2 )
return 0 ;
return F_3 ( V_4 , V_7 , V_5 , V_8 ) ;
}
static int F_4 ( struct V_9 * V_9 ,
struct V_10 * V_11 )
{
int V_12 , V_13 ;
T_2 V_14 = V_11 -> V_15 -> V_14 ;
if ( V_14 <= V_16 ) {
V_13 = 1 ;
V_11 -> V_15 -> V_17 . V_18 . type = V_19 ;
} else {
V_13 = 0 ;
V_11 -> V_15 -> V_17 . V_20 . type = V_21 ;
V_11 -> V_15 -> V_17 . V_20 . V_14 = V_14 ;
}
V_12 = F_5 ( V_9 , V_22 ,
& V_11 -> V_15 -> V_17 . V_23 [ V_13 ] ,
( sizeof( V_11 -> V_15 -> V_17 ) - V_13 ) +
V_11 -> V_15 -> V_24 , 0 ) ;
return V_12 ;
}
enum V_25 F_6 ( struct V_10 * V_11 ,
int V_7 )
{
switch ( V_7 ) {
case V_26 :
return V_11 -> V_27 ;
case V_28 :
return V_11 -> V_29 ;
case V_30 :
return V_11 -> V_31 ;
case V_32 :
return V_11 -> V_33 ;
case V_34 :
default:
return V_11 -> V_35 ;
}
}
static void F_7 ( struct V_10 * V_11 ,
int V_7 , enum V_25 V_36 )
{
switch ( V_7 ) {
case V_26 :
V_11 -> V_27 = V_36 ;
break;
case V_28 :
V_11 -> V_29 = V_36 ;
break;
case V_30 :
V_11 -> V_31 = V_36 ;
break;
case V_32 :
V_11 -> V_33 = V_36 ;
break;
case V_34 :
default:
V_11 -> V_35 = V_36 ;
break;
}
}
static void F_8 ( struct V_10 * V_11 , int V_7 )
{
switch ( V_7 ) {
case V_26 :
V_11 -> V_37 |= ( V_38 | V_39 ) ;
break;
case V_28 :
V_11 -> V_37 |= ( V_40 | V_39 ) ;
break;
case V_30 :
V_11 -> V_37 |= ( V_41 | V_39 ) ;
break;
case V_32 :
V_11 -> V_37 |= ( V_42 | V_39 ) ;
break;
case V_34 :
default:
V_11 -> V_37 |= ( V_43 | V_39 ) ;
break;
}
}
void F_9 ( struct V_44 * V_45 , int V_46 ,
struct V_47 * V_48 )
{
struct V_49 * V_50 ;
if ( ! V_45 || V_46 < 2 )
return;
switch ( V_45 -> type ) {
case V_51 :
V_50 = ( F_10 ( V_50 ) ) V_45 ;
if ( V_50 -> V_52 != 2 || V_46 <= sizeof( * V_50 ) )
return;
V_48 -> V_14 = V_50 -> V_53 ;
break;
case V_21 :
V_48 -> V_14 = V_45 -> V_54 [ 0 ] ;
break;
case V_19 :
if ( V_46 == 21 ) {
unsigned int V_55 = 0 ;
if ( ! memcmp ( & V_45 -> V_54 [ 16 ] , & V_55 , 4 ) )
V_48 -> V_14 = V_56 ;
else
V_48 -> V_14 = V_16 ;
} else if ( V_46 == 17 )
V_48 -> V_14 = V_56 ;
break;
}
}
int F_11 ( struct V_9 * V_9 ,
struct V_44 * * V_45 )
{
struct V_4 * V_4 = V_9 -> V_57 ;
if ( ! V_4 -> V_58 -> V_59 )
return 0 ;
return F_12 ( V_9 , V_22 , ( char * * ) V_45 ,
0 , V_60 ) ;
}
int F_13 ( int V_7 , struct V_10 * V_11 ,
struct V_61 * V_61 , const unsigned char * V_62 ,
struct V_44 * V_45 ,
int V_46 )
{
static const char V_63 [] = L_3 ;
char * V_64 = L_4 ;
struct V_9 * V_9 = V_61 -> V_65 ;
struct V_4 * V_4 = V_9 -> V_57 ;
enum V_25 V_36 = V_66 ;
int V_12 = V_46 , V_67 = 0 ;
if ( ! V_2 )
return 0 ;
if ( ! V_4 -> V_58 -> V_59 )
return V_66 ;
if ( V_12 <= 0 ) {
if ( V_12 && V_12 != - V_68 )
goto V_69;
V_64 = L_5 ;
V_36 =
( V_4 -> V_70 == 0 ) ? V_71 : V_72 ;
goto V_69;
}
V_36 = F_14 ( V_9 , V_22 , V_45 , V_12 , V_11 ) ;
if ( ( V_36 != V_71 ) && ( V_36 != V_66 ) ) {
if ( ( V_36 == V_72 )
|| ( V_36 == V_73 ) )
V_64 = L_6 ;
else if ( V_36 == V_74 )
V_64 = L_7 ;
goto V_69;
}
switch ( V_45 -> type ) {
case V_21 :
V_67 = 1 ;
case V_19 :
if ( V_11 -> V_37 & V_75 ) {
V_64 = L_8 ;
V_36 = V_74 ;
break;
}
if ( V_46 - sizeof( V_45 -> type ) - V_67 >=
V_11 -> V_15 -> V_24 )
V_12 = memcmp ( & V_45 -> V_54 [ V_67 ] ,
V_11 -> V_15 -> V_54 ,
V_11 -> V_15 -> V_24 ) ;
else
V_12 = - V_76 ;
if ( V_12 ) {
V_64 = L_9 ;
V_36 = V_74 ;
break;
}
V_36 = V_71 ;
break;
case V_51 :
V_11 -> V_37 |= V_77 ;
V_12 = F_15 ( V_78 ,
( const char * ) V_45 , V_12 ,
V_11 -> V_15 -> V_54 ,
V_11 -> V_15 -> V_24 ) ;
if ( V_12 == - V_79 ) {
V_36 = V_66 ;
} else if ( V_12 ) {
V_64 = L_10 ;
V_36 = V_74 ;
} else {
V_36 = V_71 ;
}
break;
default:
V_36 = V_66 ;
V_64 = L_11 ;
break;
}
V_69:
if ( V_36 != V_71 ) {
if ( ( V_2 & V_3 ) &&
( ! V_45 ||
V_45 -> type != V_51 ) ) {
if ( ! F_4 ( V_9 , V_11 ) )
V_36 = V_71 ;
}
F_16 ( V_80 , V_4 , V_62 ,
V_63 , V_64 , V_12 , 0 ) ;
} else {
F_8 ( V_11 , V_7 ) ;
}
F_7 ( V_11 , V_7 , V_36 ) ;
return V_36 ;
}
void F_17 ( struct V_10 * V_11 , struct V_61 * V_61 )
{
struct V_9 * V_9 = V_61 -> V_65 ;
int V_12 = 0 ;
if ( V_11 -> V_37 & V_77 )
return;
V_12 = F_18 ( V_11 , V_61 , NULL , NULL ) ;
if ( V_12 < 0 )
return;
F_4 ( V_9 , V_11 ) ;
}
void F_19 ( struct V_9 * V_9 )
{
struct V_4 * V_4 = V_9 -> V_57 ;
struct V_10 * V_11 ;
int V_81 , V_12 ;
if ( ! V_82 || ! V_2 || ! F_20 ( V_4 -> V_83 )
|| ! V_4 -> V_58 -> V_84 )
return;
V_81 = F_2 ( V_4 , V_85 , V_86 ) ;
V_11 = F_21 ( V_4 ) ;
if ( V_11 ) {
V_11 -> V_37 &= ~ ( V_8 | V_39 |
V_87 | V_88 |
V_89 ) ;
if ( V_81 )
V_11 -> V_37 |= V_8 ;
}
if ( ! V_81 )
V_12 = V_4 -> V_58 -> V_84 ( V_9 , V_22 ) ;
return;
}
static int F_22 ( struct V_9 * V_9 , const char * V_90 ,
const void * V_45 , T_3 V_91 )
{
if ( strcmp ( V_90 , V_22 ) == 0 ) {
if ( ! F_23 ( V_92 ) )
return - V_93 ;
return 1 ;
}
return 0 ;
}
static void F_24 ( struct V_4 * V_4 , int V_94 )
{
struct V_10 * V_11 ;
if ( ! V_82 || ! V_2 || ! F_20 ( V_4 -> V_83 ) )
return;
V_11 = F_21 ( V_4 ) ;
if ( ! V_11 )
return;
V_11 -> V_37 &= ~ V_95 ;
if ( V_94 )
V_11 -> V_37 |= V_77 ;
return;
}
int F_25 ( struct V_9 * V_9 , const char * V_90 ,
const void * V_45 , T_3 V_91 )
{
const struct V_44 * V_96 = V_45 ;
int V_97 ;
V_97 = F_22 ( V_9 , V_90 , V_45 ,
V_91 ) ;
if ( V_97 == 1 ) {
F_24 ( V_9 -> V_57 ,
( V_96 -> type == V_51 ) ? 1 : 0 ) ;
V_97 = 0 ;
}
return V_97 ;
}
int F_26 ( struct V_9 * V_9 , const char * V_90 )
{
int V_97 ;
V_97 = F_22 ( V_9 , V_90 , NULL , 0 ) ;
if ( V_97 == 1 ) {
F_24 ( V_9 -> V_57 , 0 ) ;
V_97 = 0 ;
}
return V_97 ;
}
