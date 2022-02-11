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
( (struct V_5 * ) V_19 -> V_5 ) -> F_8 ( V_19 -> V_21 , V_20 ) ;
return 0 ;
}
static int F_9 ( struct V_19 * V_19 , unsigned int V_20 )
{
( (struct V_5 * ) V_19 -> V_5 ) -> F_10 ( V_19 -> V_21 , V_20 ) ;
return 0 ;
}
static int F_11 ( struct V_19 * V_19 )
{
( (struct V_5 * ) V_19 -> V_5 ) -> F_11 ( V_19 -> V_5 ,
F_6 ( V_19 -> V_22 . type , V_19 -> V_5 ) , V_19 -> V_21 ) ;
return 0 ;
}
static int F_12 ( struct V_19 * V_19 , struct V_1 * V_23 )
{
struct V_24 * V_25 ;
struct V_22 * V_22 = & V_19 -> V_22 ;
int V_26 ;
V_25 = F_13 ( ( sizeof( * V_25 ) * V_22 -> V_27 . V_28 ) , V_29 ) ;
if ( ! V_25 )
return - V_30 ;
V_19 -> V_31 -> V_32 ( V_19 ) ;
V_23 -> V_31 -> V_33 ( V_23 ) ;
V_22 -> V_27 . V_31 -> V_33 ( & V_22 -> V_27 ) ;
for ( V_26 = 0 ; V_26 < V_22 -> V_27 . V_28 ; V_26 ++ , V_25 ++ ) {
V_25 -> V_34 = V_23 -> V_31 -> V_35 ( V_23 ) ;
V_25 -> V_36 = V_25 -> V_37 = V_22 -> V_27 . V_31 -> V_38 ( & V_22 -> V_27 ) ;
V_19 -> V_39 -> V_40 ( V_19 -> V_39 , V_25 ) ;
V_19 -> V_41 [ V_26 ] = V_25 ;
V_23 -> V_31 -> V_42 ( V_23 ) ;
V_22 -> V_27 . V_31 -> V_42 ( & V_22 -> V_27 ) ;
}
V_23 -> V_31 -> V_33 ( V_23 ) ;
V_22 -> V_27 . V_31 -> V_33 ( & V_22 -> V_27 ) ;
return 0 ;
}
static int F_14 ( struct V_19 * V_19 , struct V_1 * V_23 )
{
struct V_24 * V_25 ;
struct V_22 * V_22 = & V_19 -> V_22 ;
int V_26 ;
V_25 = F_13 ( ( sizeof( * V_25 ) * V_22 -> V_43 . V_28 ) , V_29 ) ;
if ( ! V_25 )
return - V_30 ;
V_19 -> V_31 -> V_44 ( V_19 ) ;
V_23 -> V_31 -> V_33 ( V_23 ) ;
V_22 -> V_43 . V_31 -> V_33 ( & V_22 -> V_43 ) ;
for ( V_26 = 0 ; V_26 < V_22 -> V_43 . V_28 ; V_26 ++ , V_25 ++ ) {
V_25 -> V_34 = V_23 -> V_31 -> V_35 ( V_23 ) ;
V_25 -> V_36 = V_25 -> V_37 = V_22 -> V_43 . V_31 -> V_38 ( & V_22 -> V_43 ) ;
V_19 -> V_39 -> V_40 ( V_19 -> V_39 , V_25 ) ;
V_19 -> V_41 [ V_22 -> V_27 . V_28 + V_26 ] = V_25 ;
V_23 -> V_31 -> V_42 ( V_23 ) ;
V_22 -> V_43 . V_31 -> V_42 ( & V_22 -> V_43 ) ;
}
V_23 -> V_31 -> V_33 ( V_23 ) ;
V_22 -> V_43 . V_31 -> V_33 ( & V_22 -> V_43 ) ;
return 0 ;
}
static int F_15 ( struct V_19 * V_19 )
{
struct V_24 * V_25 ;
struct V_22 * V_22 = & V_19 -> V_22 ;
int V_26 ;
if ( ! V_19 -> V_41 [ 0 ] )
return 0 ;
V_25 = V_19 -> V_41 [ 0 ] ;
V_19 -> V_39 -> V_45 ( V_19 -> V_39 , V_25 ) ;
for ( V_26 = 1 ; V_26 < V_22 -> V_27 . V_28 ; V_26 ++ ) {
V_25 = V_19 -> V_41 [ V_26 ] ;
V_19 -> V_39 -> V_45 ( V_19 -> V_39 , V_25 ) ;
V_19 -> V_41 [ V_26 ] = NULL ;
}
F_16 ( V_19 -> V_41 [ 0 ] ) ;
V_19 -> V_41 [ 0 ] = NULL ;
return 0 ;
}
static int F_17 ( struct V_19 * V_19 )
{
struct V_24 * V_25 ;
struct V_22 * V_22 = & V_19 -> V_22 ;
int V_26 ;
if ( ! V_19 -> V_41 [ V_22 -> V_27 . V_28 ] )
return 0 ;
V_25 = V_19 -> V_41 [ V_22 -> V_27 . V_28 ] ;
V_19 -> V_39 -> V_45 ( V_19 -> V_39 , V_25 ) ;
for ( V_26 = 1 ; V_26 < V_22 -> V_43 . V_28 ; V_26 ++ ) {
V_25 = V_19 -> V_41 [ V_22 -> V_27 . V_28 + V_26 ] ;
V_19 -> V_39 -> V_45 ( V_19 -> V_39 , V_25 ) ;
V_19 -> V_41 [ V_22 -> V_27 . V_28 + V_26 ] = NULL ;
}
F_16 ( V_19 -> V_41 [ V_22 -> V_27 . V_28 ] ) ;
V_19 -> V_41 [ V_22 -> V_27 . V_28 ] = NULL ;
return 0 ;
}
static int F_18 ( struct V_46 * V_46 , struct V_1 * V_47 )
{
V_47 -> V_31 -> V_33 ( V_47 ) ;
( (struct V_5 * ) V_46 -> V_5 ) -> F_19 ( V_46 -> V_21 ,
V_47 -> V_31 -> V_38 ( V_47 ) ) ;
return 0 ;
}
static int F_20 ( struct V_46 * V_46 , struct V_1 * V_47 )
{
V_47 -> V_31 -> V_33 ( V_47 ) ;
( (struct V_5 * ) V_46 -> V_5 ) -> F_21 ( V_46 -> V_21 ,
V_47 -> V_31 -> V_38 ( V_47 ) ) ;
return 0 ;
}
static int F_22 ( struct V_46 * V_46 , unsigned int V_28 )
{
unsigned int V_48 ;
for ( V_48 = 0 ; V_28 > 1 ; V_28 >>= 1 )
V_48 ++ ;
( (struct V_5 * ) V_46 -> V_5 ) -> F_23 ( V_46 -> V_21 , V_48 ) ;
return 0 ;
}
static int F_24 ( struct V_46 * V_46 , unsigned int V_49 )
{
( (struct V_5 * ) V_46 -> V_5 ) -> F_25 ( V_46 -> V_21 , V_49 ) ;
return 0 ;
}
static int F_26 ( struct V_46 * V_46 , unsigned int V_49 )
{
( (struct V_5 * ) V_46 -> V_5 ) -> F_27 ( V_46 -> V_21 , V_49 ) ;
return 0 ;
}
static int F_28 ( struct V_46 * V_46 )
{
( (struct V_5 * ) V_46 -> V_5 ) -> F_28 ( V_46 -> V_5 ,
F_6 ( V_46 -> V_22 . type , V_46 -> V_5 ) , V_46 -> V_21 ) ;
return 0 ;
}
static int F_29 ( struct V_22 * V_22 ,
const struct V_50 * V_51 ,
void * V_5 )
{
int V_52 ;
unsigned int V_53 , V_54 ;
switch ( ( (struct V_5 * ) V_5 ) -> V_6 ) {
case V_7 :
V_53 = V_55 [ V_51 -> type ] . V_56 ;
V_54 = V_55 [ V_51 -> type ] . V_57 ;
break;
case V_17 :
V_53 = V_58 [ V_51 -> type ] . V_56 ;
V_54 = V_58 [ V_51 -> type ] . V_57 ;
break;
default:
return - V_16 ;
}
V_52 = F_30 ( & V_22 -> V_27 , V_53 , V_59 , V_51 -> V_28 , V_5 ) ;
if ( V_52 )
return V_52 ;
V_52 = F_30 ( & V_22 -> V_43 , V_54 , V_59 , V_51 -> V_28 , V_5 ) ;
if ( V_52 )
goto V_60;
if ( V_51 -> type <= V_61 ) {
V_22 -> V_27 . V_31 = V_22 -> V_43 . V_31 = & V_62 ;
} else {
switch ( ( (struct V_5 * ) V_5 ) -> V_6 ) {
case V_7 :
V_22 -> V_27 . V_31 = V_22 -> V_43 . V_31 = & V_63 ;
break;
case V_17 :
V_22 -> V_27 . V_31 = V_22 -> V_43 . V_31 = & V_64 ;
break;
default:
break;
}
}
V_22 -> type = V_51 -> type ;
return 0 ;
V_60:
F_31 ( & V_22 -> V_27 ) ;
return V_52 ;
}
static int F_32 ( struct V_22 * V_22 )
{
F_31 ( & V_22 -> V_27 ) ;
F_31 ( & V_22 -> V_43 ) ;
return 0 ;
}
static int F_33 ( struct V_19 * V_19 ,
const struct V_50 * V_51 ,
struct V_65 * V_39 )
{
struct V_5 * V_5 = V_39 -> V_39 . V_5 ;
unsigned int V_66 ;
int V_52 ;
V_52 = F_29 ( & V_19 -> V_22 , V_51 , V_39 -> V_39 . V_5 ) ;
if ( V_52 )
return V_52 ;
V_19 -> V_41 = F_13 ( sizeof( void * ) * V_51 -> V_28 * 2 , V_29 ) ;
if ( ! V_19 -> V_41 ) {
V_52 = - V_30 ;
goto V_60;
}
V_19 -> V_31 = & V_67 ;
V_19 -> V_39 = V_39 ;
V_19 -> V_5 = V_5 ;
V_52 = V_5 -> V_68 ( & V_19 -> V_21 ) ;
if ( V_52 )
goto V_69;
V_5 -> V_70 ( V_39 -> V_39 . V_21 ,
F_6 ( V_19 -> V_22 . type , V_5 ) ) ;
V_5 -> V_71 ( V_5 , V_39 -> V_39 . V_21 ) ;
V_66 = ( V_51 -> V_28 & 0x7 ) | ( V_51 -> V_72 << 3 ) ;
V_5 -> V_73 ( V_39 -> V_39 . V_21 ,
F_6 ( V_19 -> V_22 . type , V_5 ) , V_66 ) ;
V_5 -> V_74 ( V_39 -> V_39 . V_21 ,
F_6 ( V_19 -> V_22 . type , V_5 ) ) ;
V_5 -> V_71 ( V_5 , V_39 -> V_39 . V_21 ) ;
return 0 ;
V_69:
F_16 ( V_19 -> V_41 ) ;
V_19 -> V_41 = NULL ;
V_60:
F_32 ( & V_19 -> V_22 ) ;
return V_52 ;
}
static int F_34 ( struct V_19 * V_19 )
{
if ( V_19 -> V_41 ) {
if ( V_19 -> V_41 [ 0 ] )
F_15 ( V_19 ) ;
if ( V_19 -> V_41 [ V_19 -> V_22 . V_27 . V_28 ] )
F_17 ( V_19 ) ;
F_16 ( V_19 -> V_41 ) ;
V_19 -> V_41 = NULL ;
}
( (struct V_5 * ) V_19 -> V_5 ) -> F_35 ( V_19 -> V_21 ) ;
V_19 -> V_5 = V_19 -> V_21 = NULL ;
F_32 ( & V_19 -> V_22 ) ;
return 0 ;
}
static int F_36 ( struct V_19 * V_19 , const struct V_75 * V_51 )
{
struct V_65 * V_39 = V_19 -> V_39 ;
struct V_50 V_76 = { 0 } ;
V_76 . type = V_19 -> V_22 . type ;
V_76 . V_28 = V_51 -> V_28 ;
V_76 . V_72 = V_51 -> V_72 ;
F_34 ( V_19 ) ;
return F_33 ( V_19 , & V_76 , V_39 ) ;
}
static int F_37 ( struct V_46 * V_46 ,
const struct V_50 * V_51 ,
struct V_65 * V_39 )
{
int V_52 ;
struct V_5 * V_5 = V_39 -> V_39 . V_5 ;
unsigned int V_48 , V_28 ;
V_52 = F_29 ( & V_46 -> V_22 , V_51 , V_39 -> V_39 . V_5 ) ;
if ( V_52 )
return V_52 ;
V_46 -> V_31 = & V_77 ;
V_46 -> V_5 = V_39 -> V_39 . V_5 ;
V_52 = V_5 -> V_78 ( & V_46 -> V_21 ) ;
if ( V_52 )
goto V_60;
for ( V_48 = 0 , V_28 = V_51 -> V_28 ; V_28 > 1 ; V_28 >>= 1 )
V_48 ++ ;
V_5 -> F_23 ( V_46 -> V_21 , V_48 ) ;
V_5 -> V_79 ( V_46 -> V_21 , 0 ) ;
V_5 -> F_25 ( V_46 -> V_21 , 0 ) ;
V_5 -> F_27 ( V_46 -> V_21 , 0 ) ;
V_5 -> F_28 ( V_5 ,
F_6 ( V_46 -> V_22 . type , V_46 -> V_5 ) , V_46 -> V_21 ) ;
return 0 ;
V_60:
F_32 ( & V_46 -> V_22 ) ;
return V_52 ;
}
static int F_38 ( struct V_46 * V_46 )
{
( (struct V_5 * ) V_46 -> V_5 ) -> F_39 ( V_46 -> V_21 ) ;
V_46 -> V_5 = V_46 -> V_21 = NULL ;
F_32 ( & V_46 -> V_22 ) ;
return 0 ;
}
static int F_40 ( struct V_80 * V_39 , enum V_4 type )
{
if ( ( (struct V_81 * ) V_39 -> V_82 ) -> V_83 & ( 0x1 << type ) )
return - V_84 ;
( (struct V_81 * ) V_39 -> V_82 ) -> V_83 |= ( 0x1 << type ) ;
return 0 ;
}
static int F_41 ( struct V_80 * V_39 , enum V_4 type )
{
( (struct V_81 * ) V_39 -> V_82 ) -> V_83 &= ~ ( 0x1 << type ) ;
return 0 ;
}
static int F_42 ( struct V_65 * V_39 ,
const struct V_50 * V_51 ,
struct V_22 * * V_85 )
{
int V_52 ;
struct V_46 * V_46 = NULL ;
struct V_19 * V_19 = NULL ;
unsigned long V_86 ;
* V_85 = NULL ;
F_43 ( & V_39 -> V_87 , V_86 ) ;
V_52 = F_40 ( & V_39 -> V_39 , V_51 -> type ) ;
F_44 ( & V_39 -> V_87 , V_86 ) ;
if ( V_52 ) {
F_45 ( V_88 L_1 ) ;
return V_52 ;
}
if ( V_51 -> type <= V_61 ) {
V_19 = F_13 ( sizeof( * V_19 ) , V_29 ) ;
if ( ! V_19 ) {
V_52 = - V_30 ;
goto error;
}
V_52 = F_33 ( V_19 , V_51 , V_39 ) ;
if ( V_52 )
goto error;
* V_85 = & V_19 -> V_22 ;
} else {
V_46 = F_13 ( sizeof( * V_46 ) , V_29 ) ;
if ( ! V_46 ) {
V_52 = - V_30 ;
goto error;
}
V_52 = F_37 ( V_46 , V_51 , V_39 ) ;
if ( V_52 )
goto error;
* V_85 = & V_46 -> V_22 ;
}
V_39 -> V_89 ( V_39 , * V_85 ) ;
V_39 -> V_90 ( V_39 ) ;
return 0 ;
error:
if ( V_19 )
F_16 ( V_19 ) ;
else if ( V_46 )
F_16 ( V_46 ) ;
F_43 ( & V_39 -> V_87 , V_86 ) ;
F_41 ( & V_39 -> V_39 , V_51 -> type ) ;
F_44 ( & V_39 -> V_87 , V_86 ) ;
return V_52 ;
}
static int F_46 ( struct V_65 * V_39 , struct V_22 * V_22 )
{
unsigned long V_86 ;
V_39 -> V_91 ( V_39 , V_22 ) ;
V_39 -> V_90 ( V_39 ) ;
F_43 ( & V_39 -> V_87 , V_86 ) ;
F_41 ( & V_39 -> V_39 , V_22 -> type ) ;
F_44 ( & V_39 -> V_87 , V_86 ) ;
if ( V_22 -> type <= V_61 ) {
F_34 ( F_47 ( V_22 , struct V_19 , V_22 ) ) ;
F_16 ( F_47 ( V_22 , struct V_19 , V_22 ) ) ;
} else {
F_38 ( F_47 ( V_22 , struct V_46 , V_22 ) ) ;
F_16 ( F_47 ( V_22 , struct V_46 , V_22 ) ) ;
}
return 0 ;
}
static int F_48 ( struct V_65 * V_39 , struct V_22 * V_22 )
{
struct V_5 * V_5 = V_39 -> V_39 . V_5 ;
if ( V_61 >= V_22 -> type ) {
V_5 -> V_74 ( V_39 -> V_39 . V_21 ,
F_6 ( V_22 -> type , V_5 ) ) ;
} else {
V_5 -> V_92 ( V_39 -> V_39 . V_21 ,
F_6 ( V_22 -> type , V_5 ) ) ;
}
return 0 ;
}
static int F_49 ( struct V_65 * V_39 , struct V_22 * V_22 )
{
struct V_5 * V_5 = V_39 -> V_39 . V_5 ;
if ( V_61 >= V_22 -> type ) {
V_5 -> V_70 ( V_39 -> V_39 . V_21 ,
F_6 ( V_22 -> type , V_5 ) ) ;
} else {
V_5 -> V_93 ( V_39 -> V_39 . V_21 ,
F_6 ( V_22 -> type , V_5 ) ) ;
}
return 0 ;
}
static int F_50 ( void * V_83 , struct V_24 * V_25 )
{
struct V_80 * V_39 = & ( (struct V_65 * ) V_83 ) -> V_39 ;
struct V_5 * V_5 = V_39 -> V_5 ;
V_5 -> V_94 ( V_39 -> V_21 , V_25 -> V_34 ) ;
V_5 -> V_95 ( V_39 -> V_21 , V_25 -> V_96 ) ;
V_5 -> V_97 ( V_39 -> V_21 , V_25 -> V_37 ) ;
V_5 -> V_71 ( V_39 -> V_5 , V_39 -> V_21 ) ;
return 0 ;
}
static int F_51 ( struct V_65 * V_39 , struct V_24 * V_25 )
{
unsigned long V_86 ;
int V_52 ;
F_43 ( & V_39 -> V_98 , V_86 ) ;
if ( ! V_25 -> V_37 && V_39 -> V_99 ) {
F_52 ( & V_39 -> V_41 , V_39 -> V_100 ,
F_50 , V_39 ) ;
V_39 -> V_99 = 0 ;
}
V_52 = F_53 ( & V_39 -> V_41 , V_25 , F_50 , V_39 ) ;
F_44 ( & V_39 -> V_98 , V_86 ) ;
return V_52 ;
}
static int F_54 ( struct V_65 * V_39 , struct V_24 * V_25 )
{
unsigned long V_86 ;
int V_52 ;
F_43 ( & V_39 -> V_98 , V_86 ) ;
V_52 = F_52 ( & V_39 -> V_41 , V_25 , F_50 , V_39 ) ;
if ( F_55 ( & V_39 -> V_41 ) ) {
F_53 ( & V_39 -> V_41 , V_39 -> V_100 ,
F_50 , V_39 ) ;
V_39 -> V_99 = 1 ;
}
F_44 ( & V_39 -> V_98 , V_86 ) ;
return V_52 ;
}
static int V_71 ( struct V_65 * V_39 )
{
struct V_5 * V_5 = V_39 -> V_39 . V_5 ;
V_5 -> V_71 ( V_5 , V_39 -> V_39 . V_21 ) ;
return 0 ;
}
int F_56 ( void * V_5 , struct V_65 * * V_101 )
{
int V_52 , V_26 ;
struct V_65 * V_65 ;
struct V_24 * V_25 ;
* V_101 = NULL ;
V_65 = F_13 ( sizeof( * V_65 ) , V_29 ) ;
if ( ! V_65 )
return - V_30 ;
V_52 = F_57 ( & V_65 -> V_39 , V_59 , V_102 , V_5 ) ;
if ( V_52 )
goto V_60;
F_58 ( & V_65 -> V_87 ) ;
F_58 ( & V_65 -> V_98 ) ;
F_59 ( & V_65 -> V_41 ) ;
V_25 = F_13 ( sizeof( * V_25 ) , V_29 ) ;
if ( ! V_25 ) {
V_52 = - V_30 ;
goto V_69;
}
V_25 -> V_34 = V_25 -> V_37 = V_25 -> V_96 = V_25 -> V_36 = 0 ;
F_60 ( & V_25 -> V_103 , & V_65 -> V_41 ) ;
V_65 -> V_100 = V_25 ;
V_65 -> V_99 = 1 ;
V_65 -> V_104 = F_42 ;
V_65 -> V_105 = F_46 ;
V_65 -> V_89 = F_48 ;
V_65 -> V_91 = F_49 ;
V_65 -> V_40 = F_51 ;
V_65 -> V_45 = F_54 ;
V_65 -> V_90 = V_71 ;
for ( V_26 = 0 ; V_26 < 8 ; V_26 ++ ) {
( (struct V_5 * ) V_5 ) -> V_70 ( V_65 -> V_39 . V_21 , V_26 ) ;
( (struct V_5 * ) V_5 ) -> V_93 ( V_65 -> V_39 . V_21 , V_26 ) ;
}
( (struct V_5 * ) V_5 ) -> V_71 ( V_5 , V_65 -> V_39 . V_21 ) ;
* V_101 = V_65 ;
return 0 ;
V_69:
F_61 ( & V_65 -> V_39 ) ;
V_60:
F_16 ( V_65 ) ;
return V_52 ;
}
int F_62 ( struct V_65 * V_65 )
{
unsigned long V_86 ;
F_43 ( & V_65 -> V_98 , V_86 ) ;
F_63 ( & V_65 -> V_41 ) ;
F_44 ( & V_65 -> V_98 , V_86 ) ;
F_61 ( & V_65 -> V_39 ) ;
F_16 ( V_65 ) ;
return 0 ;
}
