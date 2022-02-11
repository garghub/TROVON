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
default: return - V_16 ;
}
default:
return - V_16 ;
}
}
static int F_7 ( struct V_18 * V_18 , unsigned int * V_19 )
{
( (struct V_5 * ) V_18 -> V_5 ) -> F_8 ( V_18 -> V_20 , V_19 ) ;
return 0 ;
}
static int F_9 ( struct V_18 * V_18 , unsigned int V_19 )
{
( (struct V_5 * ) V_18 -> V_5 ) -> F_10 ( V_18 -> V_20 , V_19 ) ;
return 0 ;
}
static int F_11 ( struct V_18 * V_18 )
{
( (struct V_5 * ) V_18 -> V_5 ) -> F_11 ( V_18 -> V_5 ,
F_6 ( V_18 -> V_21 . type , V_18 -> V_5 ) , V_18 -> V_20 ) ;
return 0 ;
}
static int F_12 ( struct V_18 * V_18 , struct V_1 * V_22 )
{
struct V_23 * V_24 ;
struct V_21 * V_21 = & V_18 -> V_21 ;
int V_25 ;
V_24 = F_13 ( ( sizeof( * V_24 ) * V_21 -> V_26 . V_27 ) , V_28 ) ;
if ( ! V_24 )
return - V_29 ;
V_18 -> V_30 -> V_31 ( V_18 ) ;
V_22 -> V_30 -> V_32 ( V_22 ) ;
V_21 -> V_26 . V_30 -> V_32 ( & V_21 -> V_26 ) ;
for ( V_25 = 0 ; V_25 < V_21 -> V_26 . V_27 ; V_25 ++ , V_24 ++ ) {
V_24 -> V_33 = V_22 -> V_30 -> V_34 ( V_22 ) ;
V_24 -> V_35 = V_24 -> V_36 = V_21 -> V_26 . V_30 -> V_37 ( & V_21 -> V_26 ) ;
V_18 -> V_38 -> V_39 ( V_18 -> V_38 , V_24 ) ;
V_18 -> V_40 [ V_25 ] = V_24 ;
V_22 -> V_30 -> V_41 ( V_22 ) ;
V_21 -> V_26 . V_30 -> V_41 ( & V_21 -> V_26 ) ;
}
V_22 -> V_30 -> V_32 ( V_22 ) ;
V_21 -> V_26 . V_30 -> V_32 ( & V_21 -> V_26 ) ;
return 0 ;
}
static int F_14 ( struct V_18 * V_18 , struct V_1 * V_22 )
{
struct V_23 * V_24 ;
struct V_21 * V_21 = & V_18 -> V_21 ;
int V_25 ;
V_24 = F_13 ( ( sizeof( * V_24 ) * V_21 -> V_42 . V_27 ) , V_28 ) ;
if ( ! V_24 )
return - V_29 ;
V_18 -> V_30 -> V_43 ( V_18 ) ;
V_22 -> V_30 -> V_32 ( V_22 ) ;
V_21 -> V_42 . V_30 -> V_32 ( & V_21 -> V_42 ) ;
for ( V_25 = 0 ; V_25 < V_21 -> V_42 . V_27 ; V_25 ++ , V_24 ++ ) {
V_24 -> V_33 = V_22 -> V_30 -> V_34 ( V_22 ) ;
V_24 -> V_35 = V_24 -> V_36 = V_21 -> V_42 . V_30 -> V_37 ( & V_21 -> V_42 ) ;
V_18 -> V_38 -> V_39 ( V_18 -> V_38 , V_24 ) ;
V_18 -> V_40 [ V_21 -> V_26 . V_27 + V_25 ] = V_24 ;
V_22 -> V_30 -> V_41 ( V_22 ) ;
V_21 -> V_42 . V_30 -> V_41 ( & V_21 -> V_42 ) ;
}
V_22 -> V_30 -> V_32 ( V_22 ) ;
V_21 -> V_42 . V_30 -> V_32 ( & V_21 -> V_42 ) ;
return 0 ;
}
static int F_15 ( struct V_18 * V_18 )
{
struct V_23 * V_24 ;
struct V_21 * V_21 = & V_18 -> V_21 ;
int V_25 ;
if ( ! V_18 -> V_40 [ 0 ] )
return 0 ;
V_24 = V_18 -> V_40 [ 0 ] ;
V_18 -> V_38 -> V_44 ( V_18 -> V_38 , V_24 ) ;
for ( V_25 = 1 ; V_25 < V_21 -> V_26 . V_27 ; V_25 ++ ) {
V_24 = V_18 -> V_40 [ V_25 ] ;
V_18 -> V_38 -> V_44 ( V_18 -> V_38 , V_24 ) ;
V_18 -> V_40 [ V_25 ] = NULL ;
}
F_16 ( V_18 -> V_40 [ 0 ] ) ;
V_18 -> V_40 [ 0 ] = NULL ;
return 0 ;
}
static int F_17 ( struct V_18 * V_18 )
{
struct V_23 * V_24 ;
struct V_21 * V_21 = & V_18 -> V_21 ;
int V_25 ;
if ( ! V_18 -> V_40 [ V_21 -> V_26 . V_27 ] )
return 0 ;
V_24 = V_18 -> V_40 [ V_21 -> V_26 . V_27 ] ;
V_18 -> V_38 -> V_44 ( V_18 -> V_38 , V_24 ) ;
for ( V_25 = 1 ; V_25 < V_21 -> V_42 . V_27 ; V_25 ++ ) {
V_24 = V_18 -> V_40 [ V_21 -> V_26 . V_27 + V_25 ] ;
V_18 -> V_38 -> V_44 ( V_18 -> V_38 , V_24 ) ;
V_18 -> V_40 [ V_21 -> V_26 . V_27 + V_25 ] = NULL ;
}
F_16 ( V_18 -> V_40 [ V_21 -> V_26 . V_27 ] ) ;
V_18 -> V_40 [ V_21 -> V_26 . V_27 ] = NULL ;
return 0 ;
}
static int F_18 ( struct V_45 * V_45 , struct V_1 * V_46 )
{
V_46 -> V_30 -> V_32 ( V_46 ) ;
( (struct V_5 * ) V_45 -> V_5 ) -> F_19 ( V_45 -> V_20 ,
V_46 -> V_30 -> V_37 ( V_46 ) ) ;
return 0 ;
}
static int F_20 ( struct V_45 * V_45 , struct V_1 * V_46 )
{
V_46 -> V_30 -> V_32 ( V_46 ) ;
( (struct V_5 * ) V_45 -> V_5 ) -> F_21 ( V_45 -> V_20 ,
V_46 -> V_30 -> V_37 ( V_46 ) ) ;
return 0 ;
}
static int F_22 ( struct V_45 * V_45 , unsigned int V_27 )
{
unsigned int V_47 ;
for ( V_47 = 0 ; V_27 > 1 ; V_27 >>= 1 )
V_47 ++ ;
( (struct V_5 * ) V_45 -> V_5 ) -> F_23 ( V_45 -> V_20 , V_47 ) ;
return 0 ;
}
static int F_24 ( struct V_45 * V_45 , unsigned int V_48 )
{
( (struct V_5 * ) V_45 -> V_5 ) -> F_25 ( V_45 -> V_20 , V_48 ) ;
return 0 ;
}
static int F_26 ( struct V_45 * V_45 , unsigned int V_48 )
{
( (struct V_5 * ) V_45 -> V_5 ) -> F_27 ( V_45 -> V_20 , V_48 ) ;
return 0 ;
}
static int F_28 ( struct V_45 * V_45 )
{
( (struct V_5 * ) V_45 -> V_5 ) -> F_28 ( V_45 -> V_5 ,
F_6 ( V_45 -> V_21 . type , V_45 -> V_5 ) , V_45 -> V_20 ) ;
return 0 ;
}
static int F_29 ( struct V_21 * V_21 ,
const struct V_49 * V_50 ,
void * V_5 )
{
int V_51 ;
unsigned int V_52 , V_53 ;
switch ( ( (struct V_5 * ) V_5 ) -> V_6 ) {
case V_7 :
V_52 = V_54 [ V_50 -> type ] . V_55 ;
V_53 = V_54 [ V_50 -> type ] . V_56 ;
break;
case V_17 :
V_52 = V_57 [ V_50 -> type ] . V_55 ;
V_53 = V_57 [ V_50 -> type ] . V_56 ;
break;
default:
return - V_16 ;
}
V_51 = F_30 ( & V_21 -> V_26 , V_52 , V_58 , V_50 -> V_27 , V_5 ) ;
if ( V_51 )
return V_51 ;
V_51 = F_30 ( & V_21 -> V_42 , V_53 , V_58 , V_50 -> V_27 , V_5 ) ;
if ( V_51 )
goto V_59;
if ( V_50 -> type <= V_60 ) {
V_21 -> V_26 . V_30 = V_21 -> V_42 . V_30 = & V_61 ;
} else {
switch ( ( (struct V_5 * ) V_5 ) -> V_6 ) {
case V_7 :
V_21 -> V_26 . V_30 = V_21 -> V_42 . V_30 = & V_62 ;
break;
case V_17 :
V_21 -> V_26 . V_30 = V_21 -> V_42 . V_30 = & V_63 ;
break;
default:
break;
}
}
V_21 -> type = V_50 -> type ;
return 0 ;
V_59:
F_31 ( & V_21 -> V_26 ) ;
return V_51 ;
}
static int F_32 ( struct V_21 * V_21 )
{
F_31 ( & V_21 -> V_26 ) ;
F_31 ( & V_21 -> V_42 ) ;
return 0 ;
}
static int F_33 ( struct V_18 * V_18 ,
const struct V_49 * V_50 ,
struct V_64 * V_38 )
{
struct V_5 * V_5 = V_38 -> V_38 . V_5 ;
unsigned int V_65 ;
int V_51 ;
V_51 = F_29 ( & V_18 -> V_21 , V_50 , V_38 -> V_38 . V_5 ) ;
if ( V_51 )
return V_51 ;
V_18 -> V_40 = F_13 ( sizeof( void * ) * V_50 -> V_27 * 2 , V_28 ) ;
if ( ! V_18 -> V_40 ) {
V_51 = - V_29 ;
goto V_59;
}
V_18 -> V_30 = & V_66 ;
V_18 -> V_38 = V_38 ;
V_18 -> V_5 = V_5 ;
V_51 = V_5 -> V_67 ( & V_18 -> V_20 ) ;
if ( V_51 )
goto V_68;
V_5 -> V_69 ( V_38 -> V_38 . V_20 ,
F_6 ( V_18 -> V_21 . type , V_5 ) ) ;
V_5 -> V_70 ( V_5 , V_38 -> V_38 . V_20 ) ;
V_65 = ( V_50 -> V_27 & 0x7 ) | ( V_50 -> V_71 << 3 ) ;
V_5 -> V_72 ( V_38 -> V_38 . V_20 ,
F_6 ( V_18 -> V_21 . type , V_5 ) , V_65 ) ;
V_5 -> V_73 ( V_38 -> V_38 . V_20 ,
F_6 ( V_18 -> V_21 . type , V_5 ) ) ;
V_5 -> V_70 ( V_5 , V_38 -> V_38 . V_20 ) ;
return 0 ;
V_68:
F_16 ( V_18 -> V_40 ) ;
V_18 -> V_40 = NULL ;
V_59:
F_32 ( & V_18 -> V_21 ) ;
return V_51 ;
}
static int F_34 ( struct V_18 * V_18 )
{
if ( V_18 -> V_40 ) {
if ( V_18 -> V_40 [ 0 ] )
F_15 ( V_18 ) ;
if ( V_18 -> V_40 [ V_18 -> V_21 . V_26 . V_27 ] )
F_17 ( V_18 ) ;
F_16 ( V_18 -> V_40 ) ;
V_18 -> V_40 = NULL ;
}
( (struct V_5 * ) V_18 -> V_5 ) -> F_35 ( V_18 -> V_20 ) ;
V_18 -> V_5 = V_18 -> V_20 = NULL ;
F_32 ( & V_18 -> V_21 ) ;
return 0 ;
}
static int F_36 ( struct V_18 * V_18 , const struct V_74 * V_50 )
{
struct V_64 * V_38 = V_18 -> V_38 ;
struct V_49 V_75 = { 0 } ;
V_75 . type = V_18 -> V_21 . type ;
V_75 . V_27 = V_50 -> V_27 ;
V_75 . V_71 = V_50 -> V_71 ;
F_34 ( V_18 ) ;
return F_33 ( V_18 , & V_75 , V_38 ) ;
}
static int F_37 ( struct V_45 * V_45 ,
const struct V_49 * V_50 ,
struct V_64 * V_38 )
{
int V_51 ;
struct V_5 * V_5 = V_38 -> V_38 . V_5 ;
unsigned int V_47 , V_27 ;
V_51 = F_29 ( & V_45 -> V_21 , V_50 , V_38 -> V_38 . V_5 ) ;
if ( V_51 )
return V_51 ;
V_45 -> V_30 = & V_76 ;
V_45 -> V_5 = V_38 -> V_38 . V_5 ;
V_51 = V_5 -> V_77 ( & V_45 -> V_20 ) ;
if ( V_51 )
goto V_59;
for ( V_47 = 0 , V_27 = V_50 -> V_27 ; V_27 > 1 ; V_27 >>= 1 )
V_47 ++ ;
V_5 -> F_23 ( V_45 -> V_20 , V_47 ) ;
V_5 -> V_78 ( V_45 -> V_20 , 0 ) ;
V_5 -> F_25 ( V_45 -> V_20 , 0 ) ;
V_5 -> F_27 ( V_45 -> V_20 , 0 ) ;
V_5 -> F_28 ( V_5 ,
F_6 ( V_45 -> V_21 . type , V_45 -> V_5 ) , V_45 -> V_20 ) ;
return 0 ;
V_59:
F_32 ( & V_45 -> V_21 ) ;
return V_51 ;
}
static int F_38 ( struct V_45 * V_45 )
{
( (struct V_5 * ) V_45 -> V_5 ) -> F_39 ( V_45 -> V_20 ) ;
V_45 -> V_5 = V_45 -> V_20 = NULL ;
F_32 ( & V_45 -> V_21 ) ;
return 0 ;
}
static int F_40 ( struct V_79 * V_38 , enum V_4 type )
{
if ( ( (union V_80 * ) V_38 -> V_81 ) -> V_82 & ( 0x1 << type ) )
return - V_83 ;
( (union V_80 * ) V_38 -> V_81 ) -> V_82 |= ( 0x1 << type ) ;
return 0 ;
}
static int F_41 ( struct V_79 * V_38 , enum V_4 type )
{
( (union V_80 * ) V_38 -> V_81 ) -> V_82 &= ~ ( 0x1 << type ) ;
return 0 ;
}
static int F_42 ( struct V_64 * V_38 ,
const struct V_49 * V_50 ,
struct V_21 * * V_84 )
{
int V_51 ;
struct V_45 * V_45 = NULL ;
struct V_18 * V_18 = NULL ;
unsigned long V_85 ;
* V_84 = NULL ;
F_43 ( & V_38 -> V_86 , V_85 ) ;
V_51 = F_40 ( & V_38 -> V_38 , V_50 -> type ) ;
F_44 ( & V_38 -> V_86 , V_85 ) ;
if ( V_51 ) {
F_45 ( V_87 L_1 ) ;
return V_51 ;
}
if ( V_50 -> type <= V_60 ) {
V_18 = F_13 ( sizeof( * V_18 ) , V_28 ) ;
if ( ! V_18 ) {
V_51 = - V_29 ;
goto error;
}
V_51 = F_33 ( V_18 , V_50 , V_38 ) ;
if ( V_51 )
goto error;
* V_84 = & V_18 -> V_21 ;
} else {
V_45 = F_13 ( sizeof( * V_45 ) , V_28 ) ;
if ( ! V_45 ) {
V_51 = - V_29 ;
goto error;
}
V_51 = F_37 ( V_45 , V_50 , V_38 ) ;
if ( V_51 )
goto error;
* V_84 = & V_45 -> V_21 ;
}
V_38 -> V_88 ( V_38 , * V_84 ) ;
V_38 -> V_89 ( V_38 ) ;
return 0 ;
error:
if ( V_18 )
F_16 ( V_18 ) ;
else if ( V_45 )
F_16 ( V_45 ) ;
F_43 ( & V_38 -> V_86 , V_85 ) ;
F_41 ( & V_38 -> V_38 , V_50 -> type ) ;
F_44 ( & V_38 -> V_86 , V_85 ) ;
return V_51 ;
}
static int F_46 ( struct V_64 * V_38 , struct V_21 * V_21 )
{
unsigned long V_85 ;
V_38 -> V_90 ( V_38 , V_21 ) ;
V_38 -> V_89 ( V_38 ) ;
F_43 ( & V_38 -> V_86 , V_85 ) ;
F_41 ( & V_38 -> V_38 , V_21 -> type ) ;
F_44 ( & V_38 -> V_86 , V_85 ) ;
if ( V_21 -> type <= V_60 ) {
F_34 ( F_47 ( V_21 , struct V_18 , V_21 ) ) ;
F_16 ( F_47 ( V_21 , struct V_18 , V_21 ) ) ;
} else {
F_38 ( F_47 ( V_21 , struct V_45 , V_21 ) ) ;
F_16 ( F_47 ( V_21 , struct V_45 , V_21 ) ) ;
}
return 0 ;
}
static int F_48 ( struct V_64 * V_38 , struct V_21 * V_21 )
{
struct V_5 * V_5 = V_38 -> V_38 . V_5 ;
if ( V_60 >= V_21 -> type ) {
V_5 -> V_73 ( V_38 -> V_38 . V_20 ,
F_6 ( V_21 -> type , V_5 ) ) ;
} else {
V_5 -> V_91 ( V_38 -> V_38 . V_20 ,
F_6 ( V_21 -> type , V_5 ) ) ;
}
return 0 ;
}
static int F_49 ( struct V_64 * V_38 , struct V_21 * V_21 )
{
struct V_5 * V_5 = V_38 -> V_38 . V_5 ;
if ( V_60 >= V_21 -> type ) {
V_5 -> V_69 ( V_38 -> V_38 . V_20 ,
F_6 ( V_21 -> type , V_5 ) ) ;
} else {
V_5 -> V_92 ( V_38 -> V_38 . V_20 ,
F_6 ( V_21 -> type , V_5 ) ) ;
}
return 0 ;
}
static int F_50 ( void * V_82 , struct V_23 * V_24 )
{
struct V_79 * V_38 = & ( (struct V_64 * ) V_82 ) -> V_38 ;
struct V_5 * V_5 = V_38 -> V_5 ;
V_5 -> V_93 ( V_38 -> V_20 , V_24 -> V_33 ) ;
V_5 -> V_94 ( V_38 -> V_20 , V_24 -> V_95 ) ;
V_5 -> V_96 ( V_38 -> V_20 , V_24 -> V_36 ) ;
V_5 -> V_70 ( V_38 -> V_5 , V_38 -> V_20 ) ;
return 0 ;
}
static int F_51 ( struct V_64 * V_38 , struct V_23 * V_24 )
{
unsigned long V_85 ;
int V_51 ;
F_43 ( & V_38 -> V_97 , V_85 ) ;
if ( ! V_24 -> V_36 && V_38 -> V_98 ) {
F_52 ( & V_38 -> V_40 , V_38 -> V_99 ,
F_50 , V_38 ) ;
V_38 -> V_98 = 0 ;
}
V_51 = F_53 ( & V_38 -> V_40 , V_24 , F_50 , V_38 ) ;
F_44 ( & V_38 -> V_97 , V_85 ) ;
return V_51 ;
}
static int F_54 ( struct V_64 * V_38 , struct V_23 * V_24 )
{
unsigned long V_85 ;
int V_51 ;
F_43 ( & V_38 -> V_97 , V_85 ) ;
V_51 = F_52 ( & V_38 -> V_40 , V_24 , F_50 , V_38 ) ;
if ( F_55 ( & V_38 -> V_40 ) ) {
F_53 ( & V_38 -> V_40 , V_38 -> V_99 ,
F_50 , V_38 ) ;
V_38 -> V_98 = 1 ;
}
F_44 ( & V_38 -> V_97 , V_85 ) ;
return V_51 ;
}
static int V_70 ( struct V_64 * V_38 )
{
struct V_5 * V_5 = V_38 -> V_38 . V_5 ;
V_5 -> V_70 ( V_5 , V_38 -> V_38 . V_20 ) ;
return 0 ;
}
int F_56 ( void * V_5 , struct V_64 * * V_100 )
{
int V_51 , V_25 ;
struct V_64 * V_64 ;
struct V_23 * V_24 ;
* V_100 = NULL ;
V_64 = F_13 ( sizeof( * V_64 ) , V_28 ) ;
if ( ! V_64 )
return - V_29 ;
V_51 = F_57 ( & V_64 -> V_38 , V_58 , V_101 , V_5 ) ;
if ( V_51 )
goto V_59;
F_58 ( & V_64 -> V_86 ) ;
F_58 ( & V_64 -> V_97 ) ;
F_59 ( & V_64 -> V_40 ) ;
V_24 = F_13 ( sizeof( * V_24 ) , V_28 ) ;
if ( ! V_24 ) {
V_51 = - V_29 ;
goto V_68;
}
V_24 -> V_33 = V_24 -> V_36 = V_24 -> V_95 = V_24 -> V_35 = 0 ;
F_60 ( & V_24 -> V_102 , & V_64 -> V_40 ) ;
V_64 -> V_99 = V_24 ;
V_64 -> V_98 = 1 ;
V_64 -> V_103 = F_42 ;
V_64 -> V_104 = F_46 ;
V_64 -> V_88 = F_48 ;
V_64 -> V_90 = F_49 ;
V_64 -> V_39 = F_51 ;
V_64 -> V_44 = F_54 ;
V_64 -> V_89 = V_70 ;
for ( V_25 = 0 ; V_25 < 8 ; V_25 ++ ) {
( (struct V_5 * ) V_5 ) -> V_69 ( V_64 -> V_38 . V_20 , V_25 ) ;
( (struct V_5 * ) V_5 ) -> V_92 ( V_64 -> V_38 . V_20 , V_25 ) ;
}
( (struct V_5 * ) V_5 ) -> V_70 ( V_5 , V_64 -> V_38 . V_20 ) ;
* V_100 = V_64 ;
return 0 ;
V_68:
F_61 ( & V_64 -> V_38 ) ;
V_59:
F_16 ( V_64 ) ;
return V_51 ;
}
int F_62 ( struct V_64 * V_64 )
{
unsigned long V_85 ;
F_43 ( & V_64 -> V_97 , V_85 ) ;
F_63 ( & V_64 -> V_40 ) ;
F_44 ( & V_64 -> V_97 , V_85 ) ;
F_61 ( & V_64 -> V_38 ) ;
F_16 ( V_64 ) ;
return 0 ;
}
