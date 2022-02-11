static struct V_1 * F_1 ( const void * V_2 , T_1 V_3 ,
struct V_4 * V_5 )
{
struct V_1 * V_6 = F_2 ( sizeof( * V_6 ) , V_7 ) ;
if ( V_6 == NULL )
return NULL ;
V_6 -> V_6 = F_3 ( V_2 , V_3 , V_7 | V_8 ) ;
if ( ! V_6 -> V_6 ) {
F_4 ( V_6 ) ;
return NULL ;
}
if ( V_5 )
F_5 ( & V_6 -> V_5 , V_5 ) ;
return V_6 ;
}
static void F_6 ( struct V_4 * V_5 )
{
while ( ! F_7 ( V_5 ) ) {
struct V_1 * V_6 = F_8 ( V_5 ,
struct V_1 ,
V_5 ) ;
F_9 ( & V_6 -> V_5 ) ;
F_4 ( V_6 -> V_6 ) ;
F_4 ( V_6 ) ;
}
}
static int F_10 ( struct V_9 * V_10 ,
struct V_11 * V_12 )
{
struct V_13 * V_14 = F_11 ( V_10 ) ;
struct V_15 * V_16 = (struct V_15 * ) V_10 -> V_17 ;
struct V_18 * V_19 = F_12 ( V_14 ) ;
V_12 -> V_20 . integer . V_20 [ 0 ] = V_19 [ V_16 -> V_21 ] . V_22 ;
return 0 ;
}
static int F_13 ( struct V_9 * V_10 ,
struct V_11 * V_12 )
{
struct V_13 * V_14 = F_11 ( V_10 ) ;
struct V_15 * V_16 = (struct V_15 * ) V_10 -> V_17 ;
struct V_18 * V_19 = F_12 ( V_14 ) ;
if ( V_12 -> V_20 . integer . V_20 [ 0 ] == V_19 [ V_16 -> V_21 ] . V_22 )
return 0 ;
if ( V_12 -> V_20 . integer . V_20 [ 0 ] >= V_23 )
return - V_24 ;
if ( V_19 [ V_16 -> V_21 ] . V_25 )
return - V_26 ;
V_19 [ V_16 -> V_21 ] . V_22 = V_12 -> V_20 . integer . V_20 [ 0 ] ;
return 0 ;
}
static struct V_27 const * F_14 ( struct V_18 * V_28 ,
int type )
{
int V_29 ;
for ( V_29 = 0 ; V_29 < V_28 -> V_30 ; V_29 ++ )
if ( V_28 -> V_31 [ V_29 ] . type == type )
return & V_28 -> V_31 [ V_29 ] ;
return NULL ;
}
static unsigned int F_15 ( struct V_27 const * V_32 ,
unsigned int V_33 )
{
switch ( V_32 -> type ) {
case V_34 :
return V_32 -> V_35 + ( V_33 * 3 ) ;
case V_36 :
return V_32 -> V_35 + ( V_33 * 2 ) ;
case V_37 :
return V_32 -> V_35 + ( V_33 * 2 ) ;
case V_38 :
return V_32 -> V_35 + ( V_33 * 2 ) ;
case V_39 :
return V_32 -> V_35 + ( V_33 * 2 ) ;
default:
F_16 ( NULL != L_1 ) ;
return V_33 ;
}
}
static int F_17 ( struct V_18 * V_28 )
{
F_18 ( V_40 ) ;
const struct V_41 * V_41 ;
struct V_42 * V_42 = V_28 -> V_42 ;
unsigned int V_43 = 0 ;
const struct V_44 * V_45 ;
const struct V_46 * V_47 ;
const struct V_48 * V_49 ;
const struct V_50 * V_51 ;
const struct V_52 * V_32 ;
const struct V_27 * V_31 ;
const char * V_53 ;
char * V_54 , * V_55 ;
struct V_1 * V_6 ;
unsigned int V_56 ;
int V_57 = 0 ;
int V_58 , V_33 , type , V_59 ;
V_54 = F_2 ( V_60 , V_7 ) ;
if ( V_54 == NULL )
return - V_61 ;
snprintf ( V_54 , V_60 , L_2 , V_28 -> V_62 , V_28 -> V_63 ,
V_64 [ V_28 -> V_22 ] . V_54 ) ;
V_54 [ V_60 - 1 ] = '\0' ;
V_58 = F_19 ( & V_41 , V_54 , V_28 -> V_65 ) ;
if ( V_58 != 0 ) {
F_20 ( V_28 , L_3 , V_54 ) ;
goto V_66;
}
V_58 = - V_24 ;
V_43 = sizeof( * V_45 ) + sizeof( * V_47 ) + sizeof( * V_51 ) ;
if ( V_43 >= V_41 -> V_67 ) {
F_20 ( V_28 , L_4 ,
V_54 , V_41 -> V_67 ) ;
goto V_68;
}
V_45 = ( void * ) & V_41 -> V_69 [ 0 ] ;
if ( memcmp ( & V_45 -> V_70 [ 0 ] , L_5 , 4 ) != 0 ) {
F_20 ( V_28 , L_6 , V_54 ) ;
goto V_68;
}
if ( V_45 -> V_71 != 0 ) {
F_20 ( V_28 , L_7 ,
V_54 , V_45 -> V_71 ) ;
goto V_68;
}
if ( V_45 -> V_72 != V_28 -> type ) {
F_20 ( V_28 , L_8 ,
V_54 , V_45 -> V_72 , V_28 -> type ) ;
goto V_68;
}
switch ( V_28 -> type ) {
case V_73 :
V_43 = sizeof( * V_45 ) + sizeof( * V_47 ) + sizeof( * V_51 ) ;
V_47 = ( void * ) & ( V_45 [ 1 ] ) ;
V_51 = ( void * ) & ( V_47 [ 1 ] ) ;
V_59 = sizeof( * V_47 ) ;
F_21 ( V_28 , L_9 ,
V_54 , F_22 ( V_47 -> V_74 ) ,
F_22 ( V_47 -> V_75 ) ,
F_22 ( V_47 -> V_76 ) ) ;
break;
case V_77 :
V_43 = sizeof( * V_45 ) + sizeof( * V_49 ) + sizeof( * V_51 ) ;
V_49 = ( void * ) & ( V_45 [ 1 ] ) ;
V_51 = ( void * ) & ( V_49 [ 1 ] ) ;
V_59 = sizeof( * V_49 ) ;
F_21 ( V_28 , L_10 ,
V_54 , F_22 ( V_49 -> V_78 ) ,
F_22 ( V_49 -> V_79 ) ,
F_22 ( V_49 -> V_75 ) ,
F_22 ( V_49 -> V_76 ) ) ;
break;
default:
F_23 ( NULL == L_11 ) ;
goto V_68;
}
if ( F_22 ( V_45 -> V_3 ) != sizeof( * V_45 ) +
V_59 + sizeof( * V_51 ) ) {
F_20 ( V_28 , L_12 ,
V_54 , F_22 ( V_45 -> V_3 ) ) ;
goto V_68;
}
F_21 ( V_28 , L_13 , V_54 ,
F_24 ( V_51 -> V_80 ) ) ;
while ( V_43 < V_41 -> V_67 &&
V_43 - V_41 -> V_67 > sizeof( * V_32 ) ) {
V_32 = ( void * ) & ( V_41 -> V_69 [ V_43 ] ) ;
V_53 = L_14 ;
V_56 = 0 ;
V_55 = NULL ;
V_33 = F_22 ( V_32 -> V_33 ) & 0xffffff ;
type = F_25 ( V_32 -> type ) & 0xff ;
V_31 = F_14 ( V_28 , type ) ;
switch ( type ) {
case V_81 :
V_53 = L_15 ;
V_55 = F_2 ( F_22 ( V_32 -> V_3 ) + 1 ,
V_7 ) ;
break;
case V_82 :
V_53 = L_16 ;
V_55 = F_2 ( F_22 ( V_32 -> V_3 ) + 1 ,
V_7 ) ;
break;
case V_83 :
V_53 = L_17 ;
V_56 = V_33 ;
break;
case V_34 :
F_23 ( ! V_31 ) ;
V_53 = L_18 ;
V_56 = F_15 ( V_31 , V_33 ) ;
break;
case V_36 :
F_23 ( ! V_31 ) ;
V_53 = L_19 ;
V_56 = F_15 ( V_31 , V_33 ) ;
break;
case V_37 :
F_23 ( ! V_31 ) ;
V_53 = L_20 ;
V_56 = F_15 ( V_31 , V_33 ) ;
break;
case V_38 :
F_23 ( ! V_31 ) ;
V_53 = L_21 ;
V_56 = F_15 ( V_31 , V_33 ) ;
break;
case V_39 :
F_23 ( ! V_31 ) ;
V_53 = L_22 ;
V_56 = F_15 ( V_31 , V_33 ) ;
break;
default:
F_26 ( V_28 ,
L_23 ,
V_54 , V_57 , type , V_43 , V_43 ) ;
break;
}
F_21 ( V_28 , L_24 , V_54 ,
V_57 , F_22 ( V_32 -> V_3 ) , V_33 ,
V_53 ) ;
if ( V_55 ) {
memcpy ( V_55 , V_32 -> V_69 , F_22 ( V_32 -> V_3 ) ) ;
F_27 ( V_28 , L_25 , V_54 , V_55 ) ;
F_4 ( V_55 ) ;
}
if ( V_56 ) {
V_6 = F_1 ( V_32 -> V_69 ,
F_22 ( V_32 -> V_3 ) ,
& V_40 ) ;
if ( ! V_6 ) {
F_20 ( V_28 , L_26 ) ;
return - V_61 ;
}
V_58 = F_28 ( V_42 , V_56 , V_6 -> V_6 ,
F_22 ( V_32 -> V_3 ) ) ;
if ( V_58 != 0 ) {
F_20 ( V_28 ,
L_27 ,
V_54 , V_57 ,
F_22 ( V_32 -> V_3 ) , V_33 ,
V_53 , V_58 ) ;
goto V_68;
}
}
V_43 += F_22 ( V_32 -> V_3 ) + sizeof( * V_32 ) ;
V_57 ++ ;
}
V_58 = F_29 ( V_42 ) ;
if ( V_58 != 0 ) {
F_20 ( V_28 , L_28 , V_58 ) ;
goto V_68;
}
if ( V_43 > V_41 -> V_67 )
F_26 ( V_28 , L_29 ,
V_54 , V_57 , V_43 - V_41 -> V_67 ) ;
V_68:
F_29 ( V_42 ) ;
F_6 ( & V_40 ) ;
F_30 ( V_41 ) ;
V_66:
F_4 ( V_54 ) ;
return V_58 ;
}
static int F_31 ( struct V_18 * V_28 )
{
struct V_42 * V_42 = V_28 -> V_42 ;
struct V_84 V_85 ;
struct V_86 V_87 ;
struct V_88 * V_89 ;
struct V_90 * V_91 ;
void * V_92 , * V_6 ;
struct V_93 * V_32 ;
const struct V_27 * V_31 ;
unsigned int V_43 , V_94 ;
T_1 V_95 , V_96 ;
T_2 V_97 ;
int V_29 , V_58 ;
switch ( V_28 -> type ) {
case V_73 :
V_31 = F_14 ( V_28 , V_36 ) ;
break;
case V_77 :
V_31 = F_14 ( V_28 , V_37 ) ;
break;
default:
V_31 = NULL ;
break;
}
if ( V_31 == NULL ) {
F_23 ( V_31 != NULL ) ;
return - V_24 ;
}
switch ( V_28 -> type ) {
case V_73 :
V_58 = F_32 ( V_42 , V_31 -> V_35 , & V_85 ,
sizeof( V_85 ) ) ;
if ( V_58 != 0 ) {
F_20 ( V_28 , L_30 ,
V_58 ) ;
return V_58 ;
}
V_6 = & V_85 ;
V_96 = sizeof( V_85 ) ;
V_95 = F_25 ( V_85 . V_95 ) ;
F_27 ( V_28 , L_31 ,
F_25 ( V_85 . V_22 . V_98 ) ,
( F_25 ( V_85 . V_22 . V_71 ) & 0xff0000 ) >> 16 ,
( F_25 ( V_85 . V_22 . V_71 ) & 0xff00 ) >> 8 ,
F_25 ( V_85 . V_22 . V_71 ) & 0xff ,
V_95 ) ;
V_43 = sizeof( V_85 ) / 2 ;
V_94 = V_43 + ( ( sizeof( * V_89 ) * V_95 ) / 2 ) ;
break;
case V_77 :
V_58 = F_32 ( V_42 , V_31 -> V_35 , & V_87 ,
sizeof( V_87 ) ) ;
if ( V_58 != 0 ) {
F_20 ( V_28 , L_30 ,
V_58 ) ;
return V_58 ;
}
V_6 = & V_87 ;
V_96 = sizeof( V_87 ) ;
V_95 = F_25 ( V_87 . V_95 ) ;
F_27 ( V_28 , L_31 ,
F_25 ( V_87 . V_22 . V_98 ) ,
( F_25 ( V_87 . V_22 . V_71 ) & 0xff0000 ) >> 16 ,
( F_25 ( V_87 . V_22 . V_71 ) & 0xff00 ) >> 8 ,
F_25 ( V_87 . V_22 . V_71 ) & 0xff ,
V_95 ) ;
V_43 = sizeof( V_87 ) / 2 ;
V_94 = V_43 + ( ( sizeof( * V_91 ) * V_95 ) / 2 ) ;
break;
default:
F_23 ( NULL == L_11 ) ;
return - V_24 ;
}
if ( V_95 == 0 ) {
F_20 ( V_28 , L_32 ) ;
return - V_24 ;
}
if ( V_95 > 1024 ) {
F_20 ( V_28 , L_33 , V_95 ) ;
F_33 ( F_34 ( V_28 -> V_65 ) , V_99 ,
V_6 , V_96 ) ;
return - V_24 ;
}
V_58 = F_32 ( V_42 , V_31 -> V_35 + V_94 , & V_97 , sizeof( V_97 ) ) ;
if ( V_58 != 0 ) {
F_20 ( V_28 , L_34 ,
V_58 ) ;
return V_58 ;
}
if ( F_25 ( V_97 ) != 0xbedead )
F_26 ( V_28 , L_35 ,
V_94 , F_25 ( V_97 ) ) ;
V_92 = F_2 ( ( V_94 - V_43 ) * 2 , V_7 | V_8 ) ;
if ( ! V_92 )
return - V_61 ;
V_58 = F_32 ( V_42 , V_31 -> V_35 + V_43 , V_92 , ( V_94 - V_43 ) * 2 ) ;
if ( V_58 != 0 ) {
F_20 ( V_28 , L_36 ,
V_58 ) ;
goto V_66;
}
V_89 = V_92 ;
V_91 = V_92 ;
for ( V_29 = 0 ; V_29 < V_95 ; V_29 ++ ) {
switch ( V_28 -> type ) {
case V_73 :
F_27 ( V_28 , L_37 ,
V_29 , F_25 ( V_89 [ V_29 ] . V_92 . V_98 ) ,
( F_25 ( V_89 [ V_29 ] . V_92 . V_71 ) & 0xff0000 ) >> 16 ,
( F_25 ( V_89 [ V_29 ] . V_92 . V_71 ) & 0xff00 ) >> 8 ,
F_25 ( V_89 [ V_29 ] . V_92 . V_71 ) & 0xff ,
F_25 ( V_89 [ V_29 ] . V_74 ) ,
F_25 ( V_89 [ V_29 ] . V_76 ) ) ;
V_32 = F_2 ( sizeof( * V_32 ) , V_7 ) ;
if ( ! V_32 )
return - V_61 ;
V_32 -> type = V_36 ;
V_32 -> V_92 = F_25 ( V_89 [ V_29 ] . V_92 . V_98 ) ;
V_32 -> V_35 = F_25 ( V_89 [ V_29 ] . V_74 ) ;
F_5 ( & V_32 -> V_5 , & V_28 -> V_100 ) ;
V_32 = F_2 ( sizeof( * V_32 ) , V_7 ) ;
if ( ! V_32 )
return - V_61 ;
V_32 -> type = V_39 ;
V_32 -> V_92 = F_25 ( V_89 [ V_29 ] . V_92 . V_98 ) ;
V_32 -> V_35 = F_25 ( V_89 [ V_29 ] . V_76 ) ;
F_5 ( & V_32 -> V_5 , & V_28 -> V_100 ) ;
break;
case V_77 :
F_27 ( V_28 ,
L_38 ,
V_29 , F_25 ( V_91 [ V_29 ] . V_92 . V_98 ) ,
( F_25 ( V_91 [ V_29 ] . V_92 . V_71 ) & 0xff0000 ) >> 16 ,
( F_25 ( V_91 [ V_29 ] . V_92 . V_71 ) & 0xff00 ) >> 8 ,
F_25 ( V_91 [ V_29 ] . V_92 . V_71 ) & 0xff ,
F_25 ( V_91 [ V_29 ] . V_78 ) ,
F_25 ( V_91 [ V_29 ] . V_79 ) ,
F_25 ( V_91 [ V_29 ] . V_76 ) ) ;
V_32 = F_2 ( sizeof( * V_32 ) , V_7 ) ;
if ( ! V_32 )
return - V_61 ;
V_32 -> type = V_37 ;
V_32 -> V_92 = F_25 ( V_91 [ V_29 ] . V_92 . V_98 ) ;
V_32 -> V_35 = F_25 ( V_91 [ V_29 ] . V_78 ) ;
F_5 ( & V_32 -> V_5 , & V_28 -> V_100 ) ;
V_32 = F_2 ( sizeof( * V_32 ) , V_7 ) ;
if ( ! V_32 )
return - V_61 ;
V_32 -> type = V_38 ;
V_32 -> V_92 = F_25 ( V_91 [ V_29 ] . V_92 . V_98 ) ;
V_32 -> V_35 = F_25 ( V_91 [ V_29 ] . V_79 ) ;
F_5 ( & V_32 -> V_5 , & V_28 -> V_100 ) ;
V_32 = F_2 ( sizeof( * V_32 ) , V_7 ) ;
if ( ! V_32 )
return - V_61 ;
V_32 -> type = V_101 ;
V_32 -> V_92 = F_25 ( V_91 [ V_29 ] . V_92 . V_98 ) ;
V_32 -> V_35 = F_25 ( V_91 [ V_29 ] . V_76 ) ;
F_5 ( & V_32 -> V_5 , & V_28 -> V_100 ) ;
break;
}
}
V_66:
F_4 ( V_92 ) ;
return V_58 ;
}
static int F_35 ( struct V_18 * V_28 )
{
F_18 ( V_40 ) ;
struct V_42 * V_42 = V_28 -> V_42 ;
struct V_102 * V_103 ;
struct V_104 * V_105 ;
const struct V_41 * V_41 ;
const struct V_27 * V_31 ;
struct V_93 * V_106 ;
const char * V_53 ;
int V_58 , V_43 , V_107 , type , V_33 , V_56 ;
char * V_54 ;
struct V_1 * V_6 ;
int V_108 ;
V_54 = F_2 ( V_60 , V_7 ) ;
if ( V_54 == NULL )
return - V_61 ;
snprintf ( V_54 , V_60 , L_39 , V_28 -> V_62 , V_28 -> V_63 ,
V_64 [ V_28 -> V_22 ] . V_54 ) ;
V_54 [ V_60 - 1 ] = '\0' ;
V_58 = F_19 ( & V_41 , V_54 , V_28 -> V_65 ) ;
if ( V_58 != 0 ) {
F_26 ( V_28 , L_3 , V_54 ) ;
V_58 = 0 ;
goto V_66;
}
V_58 = - V_24 ;
if ( sizeof( * V_103 ) >= V_41 -> V_67 ) {
F_20 ( V_28 , L_4 ,
V_54 , V_41 -> V_67 ) ;
goto V_68;
}
V_103 = ( void * ) & V_41 -> V_69 [ 0 ] ;
if ( memcmp ( V_103 -> V_70 , L_40 , 4 ) != 0 ) {
F_20 ( V_28 , L_6 , V_54 ) ;
goto V_68;
}
switch ( F_25 ( V_103 -> V_109 ) & 0xff ) {
case 1 :
break;
default:
F_20 ( V_28 , L_41 ,
V_54 , F_25 ( V_103 -> V_109 ) & 0xff ) ;
V_58 = - V_24 ;
goto V_68;
}
F_21 ( V_28 , L_42 , V_54 ,
( F_22 ( V_103 -> V_71 ) >> 16 ) & 0xff ,
( F_22 ( V_103 -> V_71 ) >> 8 ) & 0xff ,
F_22 ( V_103 -> V_71 ) & 0xff ) ;
V_43 = F_22 ( V_103 -> V_3 ) ;
V_107 = 0 ;
while ( V_43 < V_41 -> V_67 &&
V_43 - V_41 -> V_67 > sizeof( * V_105 ) ) {
V_105 = ( void * ) ( & V_41 -> V_69 [ V_43 ] ) ;
type = F_36 ( V_105 -> type ) ;
V_33 = F_36 ( V_105 -> V_33 ) ;
F_21 ( V_28 , L_43 ,
V_54 , V_107 , F_22 ( V_105 -> V_98 ) ,
( F_22 ( V_105 -> V_71 ) >> 16 ) & 0xff ,
( F_22 ( V_105 -> V_71 ) >> 8 ) & 0xff ,
F_22 ( V_105 -> V_71 ) & 0xff ) ;
F_21 ( V_28 , L_44 ,
V_54 , V_107 , F_22 ( V_105 -> V_3 ) , V_33 , type ) ;
V_56 = 0 ;
V_53 = L_14 ;
switch ( type ) {
case ( V_81 << 8 ) :
case ( V_82 << 8 ) :
break;
case ( V_83 << 8 ) :
V_53 = L_45 ;
V_56 = V_33 ;
break;
case V_36 :
case V_39 :
case V_37 :
case V_38 :
F_21 ( V_28 , L_46 ,
V_54 , V_107 , F_22 ( V_105 -> V_3 ) ,
type , F_22 ( V_105 -> V_98 ) ) ;
V_31 = F_14 ( V_28 , type ) ;
if ( ! V_31 ) {
F_20 ( V_28 , L_47 , type ) ;
break;
}
V_56 = 0 ;
F_37 (alg_region,
&dsp->alg_regions, list) {
if ( F_22 ( V_105 -> V_98 ) == V_106 -> V_92 &&
type == V_106 -> type ) {
V_56 = V_106 -> V_35 ;
V_56 = F_15 ( V_31 ,
V_56 ) ;
V_56 += V_33 ;
}
}
if ( V_56 == 0 )
F_20 ( V_28 , L_48 ,
type , F_22 ( V_105 -> V_98 ) ) ;
break;
default:
F_20 ( V_28 , L_49 ,
V_54 , V_107 , type , V_43 ) ;
break;
}
if ( V_56 ) {
V_6 = F_1 ( V_105 -> V_69 ,
F_22 ( V_105 -> V_3 ) ,
& V_40 ) ;
if ( ! V_6 ) {
F_20 ( V_28 , L_26 ) ;
V_58 = - V_61 ;
goto V_68;
}
F_21 ( V_28 , L_50 ,
V_54 , V_107 , F_22 ( V_105 -> V_3 ) ,
V_56 ) ;
V_58 = F_28 ( V_42 , V_56 , V_6 -> V_6 ,
F_22 ( V_105 -> V_3 ) ) ;
if ( V_58 != 0 ) {
F_20 ( V_28 ,
L_51 ,
V_54 , V_107 , V_56 , V_53 ) ;
}
}
V_108 = F_22 ( V_105 -> V_3 ) % 4 ;
if ( V_108 )
V_43 += F_22 ( V_105 -> V_3 ) + ( 4 - V_108 ) + sizeof( * V_105 ) ;
else
V_43 += F_22 ( V_105 -> V_3 ) + sizeof( * V_105 ) ;
V_107 ++ ;
}
V_58 = F_29 ( V_42 ) ;
if ( V_58 != 0 )
F_20 ( V_28 , L_28 , V_58 ) ;
if ( V_43 > V_41 -> V_67 )
F_26 ( V_28 , L_29 ,
V_54 , V_107 , V_43 - V_41 -> V_67 ) ;
V_68:
F_30 ( V_41 ) ;
F_6 ( & V_40 ) ;
V_66:
F_4 ( V_54 ) ;
return V_58 ;
}
int F_38 ( struct V_18 * V_19 )
{
F_39 ( & V_19 -> V_100 ) ;
return 0 ;
}
int F_40 ( struct V_110 * V_111 ,
struct V_9 * V_10 ,
int V_112 )
{
struct V_13 * V_14 = V_111 -> V_14 ;
struct V_18 * V_113 = F_12 ( V_14 ) ;
struct V_18 * V_28 = & V_113 [ V_111 -> V_114 ] ;
int V_58 ;
int V_97 ;
switch ( V_112 ) {
case V_115 :
F_41 ( V_28 -> V_42 , V_28 -> V_35 + V_116 ,
V_117 , V_117 ) ;
if( V_28 -> V_118 ) {
V_58 = F_42 ( V_28 -> V_42 , V_28 -> V_118 , & V_97 ) ;
if ( V_58 != 0 ) {
F_20 ( V_28 , L_52 ,
V_58 ) ;
return V_58 ;
}
V_97 = ( V_97 & V_28 -> V_119 )
>> V_28 -> V_120 ;
V_58 = F_41 ( V_28 -> V_42 ,
V_28 -> V_35 + V_121 ,
V_122 , V_97 ) ;
if ( V_58 != 0 ) {
F_20 ( V_28 , L_53 ,
V_58 ) ;
return V_58 ;
}
}
V_58 = F_17 ( V_28 ) ;
if ( V_58 != 0 )
goto V_123;
V_58 = F_31 ( V_28 ) ;
if ( V_58 != 0 )
goto V_123;
V_58 = F_35 ( V_28 ) ;
if ( V_58 != 0 )
goto V_123;
F_41 ( V_28 -> V_42 , V_28 -> V_35 + V_116 ,
V_124 | V_125 ,
V_124 | V_125 ) ;
break;
case V_126 :
F_41 ( V_28 -> V_42 , V_28 -> V_35 + V_116 ,
V_124 | V_125 , 0 ) ;
F_41 ( V_28 -> V_42 , V_28 -> V_35 + V_127 ,
V_128 , 0 ) ;
F_41 ( V_28 -> V_42 , V_28 -> V_35 + V_116 ,
V_117 , 0 ) ;
break;
default:
break;
}
return 0 ;
V_123:
F_41 ( V_28 -> V_42 , V_28 -> V_35 + V_116 ,
V_117 , 0 ) ;
return V_58 ;
}
static int F_43 ( struct V_18 * V_28 )
{
unsigned int V_97 ;
int V_58 , V_129 ;
V_58 = F_41 ( V_28 -> V_42 , V_28 -> V_35 + V_130 ,
V_131 , V_131 ) ;
if ( V_58 != 0 )
return V_58 ;
V_129 = 0 ;
do {
V_58 = F_42 ( V_28 -> V_42 , V_28 -> V_35 + V_132 ,
& V_97 ) ;
if ( V_58 != 0 )
return V_58 ;
} while ( ! ( V_97 & V_133 ) && ++ V_129 < 10 );
if ( ! ( V_97 & V_133 ) ) {
F_20 ( V_28 , L_54 ) ;
return - V_26 ;
}
F_21 ( V_28 , L_55 , V_129 ) ;
F_27 ( V_28 , L_55 , V_129 ) ;
return 0 ;
}
int F_44 ( struct V_110 * V_111 ,
struct V_9 * V_10 , int V_112 )
{
struct V_13 * V_14 = V_111 -> V_14 ;
struct V_18 * V_113 = F_12 ( V_14 ) ;
struct V_18 * V_28 = & V_113 [ V_111 -> V_114 ] ;
struct V_93 * V_106 ;
unsigned int V_97 ;
int V_58 ;
switch ( V_112 ) {
case V_115 :
V_58 = F_42 ( V_28 -> V_42 , V_134 , & V_97 ) ;
if ( V_58 != 0 ) {
F_20 ( V_28 , L_52 ,
V_58 ) ;
return V_58 ;
}
V_97 = ( V_97 & V_135 )
>> V_136 ;
V_58 = F_41 ( V_28 -> V_42 ,
V_28 -> V_35 + V_137 ,
V_138 , V_97 ) ;
if ( V_58 != 0 ) {
F_20 ( V_28 , L_53 ,
V_58 ) ;
return V_58 ;
}
if ( V_28 -> V_139 ) {
V_58 = F_42 ( V_28 -> V_42 ,
V_28 -> V_35 + V_137 , & V_97 ) ;
if ( V_58 != 0 ) {
F_45 ( V_28 -> V_65 ,
L_56 , V_58 ) ;
return V_58 ;
}
if ( ( V_97 & V_138 ) >= 3 ) {
V_58 = F_46 ( V_28 -> V_139 ) ;
if ( V_58 != 0 ) {
F_45 ( V_28 -> V_65 ,
L_57 ,
V_58 ) ;
return V_58 ;
}
V_58 = F_47 ( V_28 -> V_139 ,
1800000 ,
1800000 ) ;
if ( V_58 != 0 ) {
F_45 ( V_28 -> V_65 ,
L_58 ,
V_58 ) ;
return V_58 ;
}
}
}
V_58 = F_43 ( V_28 ) ;
if ( V_58 != 0 )
return V_58 ;
V_58 = F_17 ( V_28 ) ;
if ( V_58 != 0 )
goto V_123;
V_58 = F_31 ( V_28 ) ;
if ( V_58 != 0 )
goto V_123;
V_58 = F_35 ( V_28 ) ;
if ( V_58 != 0 )
goto V_123;
V_58 = F_41 ( V_28 -> V_42 ,
V_28 -> V_35 + V_130 ,
V_140 | V_141 ,
V_140 | V_141 ) ;
if ( V_58 != 0 )
goto V_123;
V_28 -> V_25 = true ;
break;
case V_126 :
V_28 -> V_25 = false ;
F_41 ( V_28 -> V_42 , V_28 -> V_35 + V_130 ,
V_131 | V_140 |
V_141 , 0 ) ;
F_48 ( V_28 -> V_42 , V_28 -> V_35 + V_142 , 0 ) ;
F_48 ( V_28 -> V_42 , V_28 -> V_35 + V_143 , 0 ) ;
F_48 ( V_28 -> V_42 , V_28 -> V_35 + V_144 , 0 ) ;
if ( V_28 -> V_139 ) {
V_58 = F_47 ( V_28 -> V_139 , 1200000 ,
1800000 ) ;
if ( V_58 != 0 )
F_49 ( V_28 -> V_65 ,
L_59 ,
V_58 ) ;
V_58 = F_50 ( V_28 -> V_139 ) ;
if ( V_58 != 0 )
F_45 ( V_28 -> V_65 ,
L_57 ,
V_58 ) ;
}
while ( ! F_7 ( & V_28 -> V_100 ) ) {
V_106 = F_8 ( & V_28 -> V_100 ,
struct V_93 ,
V_5 ) ;
F_9 ( & V_106 -> V_5 ) ;
F_4 ( V_106 ) ;
}
break;
default:
break;
}
return 0 ;
V_123:
F_41 ( V_28 -> V_42 , V_28 -> V_35 + V_130 ,
V_131 | V_140 | V_141 , 0 ) ;
return V_58 ;
}
int F_51 ( struct V_18 * V_19 , bool V_139 )
{
int V_58 ;
V_58 = F_41 ( V_19 -> V_42 , V_19 -> V_35 + V_130 ,
V_145 , 0 ) ;
if ( V_58 != 0 ) {
F_20 ( V_19 , L_60 , V_58 ) ;
return V_58 ;
}
F_39 ( & V_19 -> V_100 ) ;
if ( V_139 ) {
V_19 -> V_139 = F_52 ( V_19 -> V_65 , L_61 ) ;
if ( F_53 ( V_19 -> V_139 ) ) {
V_58 = F_54 ( V_19 -> V_139 ) ;
F_45 ( V_19 -> V_65 , L_62 , V_58 ) ;
return V_58 ;
}
V_58 = F_46 ( V_19 -> V_139 ) ;
if ( V_58 != 0 ) {
F_45 ( V_19 -> V_65 , L_63 ,
V_58 ) ;
return V_58 ;
}
V_58 = F_47 ( V_19 -> V_139 , 1200000 , 1800000 ) ;
if ( V_58 != 0 ) {
F_45 ( V_19 -> V_65 , L_64 ,
V_58 ) ;
return V_58 ;
}
V_58 = F_50 ( V_19 -> V_139 ) ;
if ( V_58 != 0 ) {
F_45 ( V_19 -> V_65 , L_65 ,
V_58 ) ;
return V_58 ;
}
}
return 0 ;
}
