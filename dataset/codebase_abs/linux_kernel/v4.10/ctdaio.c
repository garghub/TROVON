static int F_1 ( struct V_1 * V_1 )
{
return V_1 -> V_2 = V_1 -> V_3 ;
}
static int F_2 ( const struct V_1 * V_1 )
{
return V_1 -> V_2 ;
}
static int F_3 ( struct V_1 * V_1 )
{
return V_1 -> V_2 += 2 ;
}
static int F_4 ( struct V_1 * V_1 )
{
return V_1 -> V_2 += 0x200 ;
}
static int F_5 ( struct V_1 * V_1 )
{
return V_1 -> V_2 += 0x100 ;
}
static unsigned int F_6 ( enum V_4 type , struct V_5 * V_5 )
{
switch ( V_5 -> V_6 ) {
case V_7 :
switch ( type ) {
case V_8 : return 0 ;
case V_9 : return 0 ;
case V_10 : return 1 ;
case V_11 : return 4 ;
case V_12 : return 7 ;
case V_13 : return 5 ;
case V_14 : return 6 ;
case V_15 : return 7 ;
default: return - V_16 ;
}
case V_17 :
switch ( type ) {
case V_8 : return 0 ;
case V_9 : return 0 ;
case V_11 : return 4 ;
case V_12 : return 7 ;
case V_13 : return 5 ;
case V_14 : return 6 ;
case V_15 : return 4 ;
case V_18 : return 5 ;
default: return - V_16 ;
}
default:
return - V_16 ;
}
}
static int F_7 ( struct V_19 * V_19 , unsigned int * V_20 )
{
V_19 -> V_5 -> V_21 ( V_19 -> V_22 , V_20 ) ;
return 0 ;
}
static int F_8 ( struct V_19 * V_19 , unsigned int V_20 )
{
V_19 -> V_5 -> V_23 ( V_19 -> V_22 , V_20 ) ;
return 0 ;
}
static int F_9 ( struct V_19 * V_19 )
{
V_19 -> V_5 -> F_9 ( V_19 -> V_5 ,
F_6 ( V_19 -> V_24 . type , V_19 -> V_5 ) , V_19 -> V_22 ) ;
return 0 ;
}
static int F_10 ( struct V_19 * V_19 , struct V_1 * V_25 )
{
struct V_26 * V_27 ;
struct V_24 * V_24 = & V_19 -> V_24 ;
int V_28 ;
V_27 = F_11 ( ( sizeof( * V_27 ) * V_24 -> V_29 . V_30 ) , V_31 ) ;
if ( ! V_27 )
return - V_32 ;
V_19 -> V_33 -> V_34 ( V_19 ) ;
V_25 -> V_33 -> V_35 ( V_25 ) ;
V_24 -> V_29 . V_33 -> V_35 ( & V_24 -> V_29 ) ;
for ( V_28 = 0 ; V_28 < V_24 -> V_29 . V_30 ; V_28 ++ , V_27 ++ ) {
V_27 -> V_36 = V_25 -> V_33 -> V_37 ( V_25 ) ;
V_27 -> V_38 = V_27 -> V_39 = V_24 -> V_29 . V_33 -> V_40 ( & V_24 -> V_29 ) ;
V_19 -> V_41 -> V_42 ( V_19 -> V_41 , V_27 ) ;
V_19 -> V_43 [ V_28 ] = V_27 ;
V_25 -> V_33 -> V_44 ( V_25 ) ;
V_24 -> V_29 . V_33 -> V_44 ( & V_24 -> V_29 ) ;
}
V_25 -> V_33 -> V_35 ( V_25 ) ;
V_24 -> V_29 . V_33 -> V_35 ( & V_24 -> V_29 ) ;
return 0 ;
}
static int F_12 ( struct V_19 * V_19 , struct V_1 * V_25 )
{
struct V_26 * V_27 ;
struct V_24 * V_24 = & V_19 -> V_24 ;
int V_28 ;
V_27 = F_11 ( ( sizeof( * V_27 ) * V_24 -> V_45 . V_30 ) , V_31 ) ;
if ( ! V_27 )
return - V_32 ;
V_19 -> V_33 -> V_46 ( V_19 ) ;
V_25 -> V_33 -> V_35 ( V_25 ) ;
V_24 -> V_45 . V_33 -> V_35 ( & V_24 -> V_45 ) ;
for ( V_28 = 0 ; V_28 < V_24 -> V_45 . V_30 ; V_28 ++ , V_27 ++ ) {
V_27 -> V_36 = V_25 -> V_33 -> V_37 ( V_25 ) ;
V_27 -> V_38 = V_27 -> V_39 = V_24 -> V_45 . V_33 -> V_40 ( & V_24 -> V_45 ) ;
V_19 -> V_41 -> V_42 ( V_19 -> V_41 , V_27 ) ;
V_19 -> V_43 [ V_24 -> V_29 . V_30 + V_28 ] = V_27 ;
V_25 -> V_33 -> V_44 ( V_25 ) ;
V_24 -> V_45 . V_33 -> V_44 ( & V_24 -> V_45 ) ;
}
V_25 -> V_33 -> V_35 ( V_25 ) ;
V_24 -> V_45 . V_33 -> V_35 ( & V_24 -> V_45 ) ;
return 0 ;
}
static int F_13 ( struct V_19 * V_19 )
{
struct V_26 * V_27 ;
struct V_24 * V_24 = & V_19 -> V_24 ;
int V_28 ;
if ( ! V_19 -> V_43 [ 0 ] )
return 0 ;
V_27 = V_19 -> V_43 [ 0 ] ;
V_19 -> V_41 -> V_47 ( V_19 -> V_41 , V_27 ) ;
for ( V_28 = 1 ; V_28 < V_24 -> V_29 . V_30 ; V_28 ++ ) {
V_27 = V_19 -> V_43 [ V_28 ] ;
V_19 -> V_41 -> V_47 ( V_19 -> V_41 , V_27 ) ;
V_19 -> V_43 [ V_28 ] = NULL ;
}
F_14 ( V_19 -> V_43 [ 0 ] ) ;
V_19 -> V_43 [ 0 ] = NULL ;
return 0 ;
}
static int F_15 ( struct V_19 * V_19 )
{
struct V_26 * V_27 ;
struct V_24 * V_24 = & V_19 -> V_24 ;
int V_28 ;
if ( ! V_19 -> V_43 [ V_24 -> V_29 . V_30 ] )
return 0 ;
V_27 = V_19 -> V_43 [ V_24 -> V_29 . V_30 ] ;
V_19 -> V_41 -> V_47 ( V_19 -> V_41 , V_27 ) ;
for ( V_28 = 1 ; V_28 < V_24 -> V_45 . V_30 ; V_28 ++ ) {
V_27 = V_19 -> V_43 [ V_24 -> V_29 . V_30 + V_28 ] ;
V_19 -> V_41 -> V_47 ( V_19 -> V_41 , V_27 ) ;
V_19 -> V_43 [ V_24 -> V_29 . V_30 + V_28 ] = NULL ;
}
F_14 ( V_19 -> V_43 [ V_24 -> V_29 . V_30 ] ) ;
V_19 -> V_43 [ V_24 -> V_29 . V_30 ] = NULL ;
return 0 ;
}
static int F_16 ( struct V_48 * V_48 , struct V_1 * V_49 )
{
V_49 -> V_33 -> V_35 ( V_49 ) ;
V_48 -> V_5 -> V_50 ( V_48 -> V_22 , V_49 -> V_33 -> V_40 ( V_49 ) ) ;
return 0 ;
}
static int F_17 ( struct V_48 * V_48 , struct V_1 * V_49 )
{
V_49 -> V_33 -> V_35 ( V_49 ) ;
V_48 -> V_5 -> V_51 ( V_48 -> V_22 , V_49 -> V_33 -> V_40 ( V_49 ) ) ;
return 0 ;
}
static int F_18 ( struct V_48 * V_48 , unsigned int V_30 )
{
unsigned int V_52 ;
for ( V_52 = 0 ; V_30 > 1 ; V_30 >>= 1 )
V_52 ++ ;
V_48 -> V_5 -> V_53 ( V_48 -> V_22 , V_52 ) ;
return 0 ;
}
static int F_19 ( struct V_48 * V_48 , unsigned int V_54 )
{
V_48 -> V_5 -> V_55 ( V_48 -> V_22 , V_54 ) ;
return 0 ;
}
static int F_20 ( struct V_48 * V_48 , unsigned int V_54 )
{
V_48 -> V_5 -> V_56 ( V_48 -> V_22 , V_54 ) ;
return 0 ;
}
static int F_21 ( struct V_48 * V_48 )
{
V_48 -> V_5 -> F_21 ( V_48 -> V_5 ,
F_6 ( V_48 -> V_24 . type , V_48 -> V_5 ) , V_48 -> V_22 ) ;
return 0 ;
}
static int F_22 ( struct V_24 * V_24 ,
const struct V_57 * V_58 ,
struct V_5 * V_5 )
{
int V_59 ;
unsigned int V_60 , V_61 ;
switch ( V_5 -> V_6 ) {
case V_7 :
V_60 = V_62 [ V_58 -> type ] . V_63 ;
V_61 = V_62 [ V_58 -> type ] . V_64 ;
break;
case V_17 :
V_60 = V_65 [ V_58 -> type ] . V_63 ;
V_61 = V_65 [ V_58 -> type ] . V_64 ;
break;
default:
return - V_16 ;
}
V_59 = F_23 ( & V_24 -> V_29 , V_60 , V_66 , V_58 -> V_30 , V_5 ) ;
if ( V_59 )
return V_59 ;
V_59 = F_23 ( & V_24 -> V_45 , V_61 , V_66 , V_58 -> V_30 , V_5 ) ;
if ( V_59 )
goto V_67;
if ( V_58 -> type <= V_68 ) {
V_24 -> V_29 . V_33 = V_24 -> V_45 . V_33 = & V_69 ;
} else {
switch ( V_5 -> V_6 ) {
case V_7 :
V_24 -> V_29 . V_33 = V_24 -> V_45 . V_33 = & V_70 ;
break;
case V_17 :
V_24 -> V_29 . V_33 = V_24 -> V_45 . V_33 = & V_71 ;
break;
default:
break;
}
}
V_24 -> type = V_58 -> type ;
return 0 ;
V_67:
F_24 ( & V_24 -> V_29 ) ;
return V_59 ;
}
static int F_25 ( struct V_24 * V_24 )
{
F_24 ( & V_24 -> V_29 ) ;
F_24 ( & V_24 -> V_45 ) ;
return 0 ;
}
static int F_26 ( struct V_19 * V_19 ,
const struct V_57 * V_58 ,
struct V_72 * V_41 )
{
struct V_5 * V_5 = V_41 -> V_41 . V_5 ;
unsigned int V_73 ;
int V_59 ;
V_59 = F_22 ( & V_19 -> V_24 , V_58 , V_41 -> V_41 . V_5 ) ;
if ( V_59 )
return V_59 ;
V_19 -> V_43 = F_11 ( sizeof( void * ) * V_58 -> V_30 * 2 , V_31 ) ;
if ( ! V_19 -> V_43 ) {
V_59 = - V_32 ;
goto V_67;
}
V_19 -> V_33 = & V_74 ;
V_19 -> V_41 = V_41 ;
V_19 -> V_5 = V_5 ;
V_59 = V_5 -> V_75 ( & V_19 -> V_22 ) ;
if ( V_59 )
goto V_76;
V_5 -> V_77 ( V_41 -> V_41 . V_22 ,
F_6 ( V_19 -> V_24 . type , V_5 ) ) ;
V_5 -> V_78 ( V_5 , V_41 -> V_41 . V_22 ) ;
V_73 = ( V_58 -> V_30 & 0x7 ) | ( V_58 -> V_79 << 3 ) ;
V_5 -> V_80 ( V_41 -> V_41 . V_22 ,
F_6 ( V_19 -> V_24 . type , V_5 ) , V_73 ) ;
V_5 -> V_81 ( V_41 -> V_41 . V_22 ,
F_6 ( V_19 -> V_24 . type , V_5 ) ) ;
V_5 -> V_78 ( V_5 , V_41 -> V_41 . V_22 ) ;
return 0 ;
V_76:
F_14 ( V_19 -> V_43 ) ;
V_19 -> V_43 = NULL ;
V_67:
F_25 ( & V_19 -> V_24 ) ;
return V_59 ;
}
static int F_27 ( struct V_19 * V_19 )
{
if ( V_19 -> V_43 ) {
if ( V_19 -> V_43 [ 0 ] )
F_13 ( V_19 ) ;
if ( V_19 -> V_43 [ V_19 -> V_24 . V_29 . V_30 ] )
F_15 ( V_19 ) ;
F_14 ( V_19 -> V_43 ) ;
V_19 -> V_43 = NULL ;
}
V_19 -> V_5 -> V_82 ( V_19 -> V_22 ) ;
V_19 -> V_5 = V_19 -> V_22 = NULL ;
F_25 ( & V_19 -> V_24 ) ;
return 0 ;
}
static int F_28 ( struct V_19 * V_19 , const struct V_83 * V_58 )
{
struct V_72 * V_41 = V_19 -> V_41 ;
struct V_57 V_84 = { 0 } ;
V_84 . type = V_19 -> V_24 . type ;
V_84 . V_30 = V_58 -> V_30 ;
V_84 . V_79 = V_58 -> V_79 ;
F_27 ( V_19 ) ;
return F_26 ( V_19 , & V_84 , V_41 ) ;
}
static int F_29 ( struct V_48 * V_48 ,
const struct V_57 * V_58 ,
struct V_72 * V_41 )
{
int V_59 ;
struct V_5 * V_5 = V_41 -> V_41 . V_5 ;
unsigned int V_52 , V_30 ;
V_59 = F_22 ( & V_48 -> V_24 , V_58 , V_41 -> V_41 . V_5 ) ;
if ( V_59 )
return V_59 ;
V_48 -> V_33 = & V_85 ;
V_48 -> V_5 = V_41 -> V_41 . V_5 ;
V_59 = V_5 -> V_86 ( & V_48 -> V_22 ) ;
if ( V_59 )
goto V_67;
for ( V_52 = 0 , V_30 = V_58 -> V_30 ; V_30 > 1 ; V_30 >>= 1 )
V_52 ++ ;
V_5 -> V_53 ( V_48 -> V_22 , V_52 ) ;
V_5 -> V_87 ( V_48 -> V_22 , 0 ) ;
V_5 -> V_55 ( V_48 -> V_22 , 0 ) ;
V_5 -> V_56 ( V_48 -> V_22 , 0 ) ;
V_5 -> F_21 ( V_5 ,
F_6 ( V_48 -> V_24 . type , V_48 -> V_5 ) , V_48 -> V_22 ) ;
return 0 ;
V_67:
F_25 ( & V_48 -> V_24 ) ;
return V_59 ;
}
static int F_30 ( struct V_48 * V_48 )
{
V_48 -> V_5 -> V_88 ( V_48 -> V_22 ) ;
V_48 -> V_5 = V_48 -> V_22 = NULL ;
F_25 ( & V_48 -> V_24 ) ;
return 0 ;
}
static int F_31 ( struct V_89 * V_41 , enum V_4 type )
{
if ( ( (struct V_90 * ) V_41 -> V_91 ) -> V_92 & ( 0x1 << type ) )
return - V_93 ;
( (struct V_90 * ) V_41 -> V_91 ) -> V_92 |= ( 0x1 << type ) ;
return 0 ;
}
static int F_32 ( struct V_89 * V_41 , enum V_4 type )
{
( (struct V_90 * ) V_41 -> V_91 ) -> V_92 &= ~ ( 0x1 << type ) ;
return 0 ;
}
static int F_33 ( struct V_72 * V_41 ,
const struct V_57 * V_58 ,
struct V_24 * * V_94 )
{
int V_59 ;
unsigned long V_95 ;
* V_94 = NULL ;
F_34 ( & V_41 -> V_96 , V_95 ) ;
V_59 = F_31 ( & V_41 -> V_41 , V_58 -> type ) ;
F_35 ( & V_41 -> V_96 , V_95 ) ;
if ( V_59 ) {
F_36 ( V_41 -> V_97 -> V_98 ,
L_1 ) ;
return V_59 ;
}
V_59 = - V_32 ;
if ( V_58 -> type <= V_68 ) {
struct V_19 * V_19 = F_11 ( sizeof( * V_19 ) , V_31 ) ;
if ( ! V_19 )
goto error;
V_59 = F_26 ( V_19 , V_58 , V_41 ) ;
if ( V_59 ) {
F_14 ( V_19 ) ;
goto error;
}
* V_94 = & V_19 -> V_24 ;
} else {
struct V_48 * V_48 = F_11 ( sizeof( * V_48 ) , V_31 ) ;
if ( ! V_48 )
goto error;
V_59 = F_29 ( V_48 , V_58 , V_41 ) ;
if ( V_59 ) {
F_14 ( V_48 ) ;
goto error;
}
* V_94 = & V_48 -> V_24 ;
}
V_41 -> V_99 ( V_41 , * V_94 ) ;
V_41 -> V_100 ( V_41 ) ;
return 0 ;
error:
F_34 ( & V_41 -> V_96 , V_95 ) ;
F_32 ( & V_41 -> V_41 , V_58 -> type ) ;
F_35 ( & V_41 -> V_96 , V_95 ) ;
return V_59 ;
}
static int F_37 ( struct V_72 * V_41 , struct V_24 * V_24 )
{
unsigned long V_95 ;
V_41 -> V_101 ( V_41 , V_24 ) ;
V_41 -> V_100 ( V_41 ) ;
F_34 ( & V_41 -> V_96 , V_95 ) ;
F_32 ( & V_41 -> V_41 , V_24 -> type ) ;
F_35 ( & V_41 -> V_96 , V_95 ) ;
if ( V_24 -> type <= V_68 ) {
F_27 ( F_38 ( V_24 , struct V_19 , V_24 ) ) ;
F_14 ( F_38 ( V_24 , struct V_19 , V_24 ) ) ;
} else {
F_30 ( F_38 ( V_24 , struct V_48 , V_24 ) ) ;
F_14 ( F_38 ( V_24 , struct V_48 , V_24 ) ) ;
}
return 0 ;
}
static int F_39 ( struct V_72 * V_41 , struct V_24 * V_24 )
{
struct V_5 * V_5 = V_41 -> V_41 . V_5 ;
if ( V_68 >= V_24 -> type ) {
V_5 -> V_81 ( V_41 -> V_41 . V_22 ,
F_6 ( V_24 -> type , V_5 ) ) ;
} else {
V_5 -> V_102 ( V_41 -> V_41 . V_22 ,
F_6 ( V_24 -> type , V_5 ) ) ;
}
return 0 ;
}
static int F_40 ( struct V_72 * V_41 , struct V_24 * V_24 )
{
struct V_5 * V_5 = V_41 -> V_41 . V_5 ;
if ( V_68 >= V_24 -> type ) {
V_5 -> V_77 ( V_41 -> V_41 . V_22 ,
F_6 ( V_24 -> type , V_5 ) ) ;
} else {
V_5 -> V_103 ( V_41 -> V_41 . V_22 ,
F_6 ( V_24 -> type , V_5 ) ) ;
}
return 0 ;
}
static int F_41 ( void * V_92 , struct V_26 * V_27 )
{
struct V_89 * V_41 = & ( (struct V_72 * ) V_92 ) -> V_41 ;
struct V_5 * V_5 = V_41 -> V_5 ;
V_5 -> V_104 ( V_41 -> V_22 , V_27 -> V_36 ) ;
V_5 -> V_105 ( V_41 -> V_22 , V_27 -> V_106 ) ;
V_5 -> V_107 ( V_41 -> V_22 , V_27 -> V_39 ) ;
V_5 -> V_78 ( V_41 -> V_5 , V_41 -> V_22 ) ;
return 0 ;
}
static int F_42 ( struct V_72 * V_41 , struct V_26 * V_27 )
{
unsigned long V_95 ;
int V_59 ;
F_34 ( & V_41 -> V_108 , V_95 ) ;
if ( ! V_27 -> V_39 && V_41 -> V_109 ) {
F_43 ( & V_41 -> V_43 , V_41 -> V_110 ,
F_41 , V_41 ) ;
V_41 -> V_109 = 0 ;
}
V_59 = F_44 ( & V_41 -> V_43 , V_27 , F_41 , V_41 ) ;
F_35 ( & V_41 -> V_108 , V_95 ) ;
return V_59 ;
}
static int F_45 ( struct V_72 * V_41 , struct V_26 * V_27 )
{
unsigned long V_95 ;
int V_59 ;
F_34 ( & V_41 -> V_108 , V_95 ) ;
V_59 = F_43 ( & V_41 -> V_43 , V_27 , F_41 , V_41 ) ;
if ( F_46 ( & V_41 -> V_43 ) ) {
F_44 ( & V_41 -> V_43 , V_41 -> V_110 ,
F_41 , V_41 ) ;
V_41 -> V_109 = 1 ;
}
F_35 ( & V_41 -> V_108 , V_95 ) ;
return V_59 ;
}
static int V_78 ( struct V_72 * V_41 )
{
struct V_5 * V_5 = V_41 -> V_41 . V_5 ;
V_5 -> V_78 ( V_5 , V_41 -> V_41 . V_22 ) ;
return 0 ;
}
int F_47 ( struct V_5 * V_5 , struct V_72 * * V_111 )
{
int V_59 , V_28 ;
struct V_72 * V_72 ;
struct V_26 * V_27 ;
* V_111 = NULL ;
V_72 = F_11 ( sizeof( * V_72 ) , V_31 ) ;
if ( ! V_72 )
return - V_32 ;
V_59 = F_48 ( & V_72 -> V_41 , V_66 , V_112 , V_5 ) ;
if ( V_59 )
goto V_67;
F_49 ( & V_72 -> V_96 ) ;
F_49 ( & V_72 -> V_108 ) ;
F_50 ( & V_72 -> V_43 ) ;
V_27 = F_11 ( sizeof( * V_27 ) , V_31 ) ;
if ( ! V_27 ) {
V_59 = - V_32 ;
goto V_76;
}
V_27 -> V_36 = V_27 -> V_39 = V_27 -> V_106 = V_27 -> V_38 = 0 ;
F_51 ( & V_27 -> V_113 , & V_72 -> V_43 ) ;
V_72 -> V_110 = V_27 ;
V_72 -> V_109 = 1 ;
V_72 -> V_114 = F_33 ;
V_72 -> V_115 = F_37 ;
V_72 -> V_99 = F_39 ;
V_72 -> V_101 = F_40 ;
V_72 -> V_42 = F_42 ;
V_72 -> V_47 = F_45 ;
V_72 -> V_100 = V_78 ;
V_72 -> V_97 = V_5 -> V_97 ;
for ( V_28 = 0 ; V_28 < 8 ; V_28 ++ ) {
V_5 -> V_77 ( V_72 -> V_41 . V_22 , V_28 ) ;
V_5 -> V_103 ( V_72 -> V_41 . V_22 , V_28 ) ;
}
V_5 -> V_78 ( V_5 , V_72 -> V_41 . V_22 ) ;
* V_111 = V_72 ;
return 0 ;
V_76:
F_52 ( & V_72 -> V_41 ) ;
V_67:
F_14 ( V_72 ) ;
return V_59 ;
}
int F_53 ( struct V_72 * V_72 )
{
unsigned long V_95 ;
F_34 ( & V_72 -> V_108 , V_95 ) ;
F_54 ( & V_72 -> V_43 ) ;
F_35 ( & V_72 -> V_108 , V_95 ) ;
F_52 ( & V_72 -> V_41 ) ;
F_14 ( V_72 ) ;
return 0 ;
}
