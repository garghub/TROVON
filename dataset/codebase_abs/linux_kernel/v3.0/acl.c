static T_1 F_1 ( int V_1 )
{
if ( V_1 <= 4 ) {
return sizeof( struct V_2 )
+ V_1 * sizeof( struct V_3 ) ;
} else {
return sizeof( struct V_2 )
+ 4 * sizeof( struct V_3 )
+ ( V_1 - 4 ) * sizeof( struct V_4 ) ;
}
}
static int F_2 ( T_1 V_5 )
{
T_1 V_6 ;
V_5 -= sizeof( struct V_2 ) ;
if ( V_5 < 4 * sizeof( struct V_3 ) ) {
if ( V_5 % sizeof( struct V_3 ) )
return - 1 ;
return V_5 / sizeof( struct V_3 ) ;
} else {
V_6 = V_5 - 4 * sizeof( struct V_3 ) ;
if ( V_6 % sizeof( struct V_4 ) )
return - 1 ;
return V_6 / sizeof( struct V_4 ) + 4 ;
}
}
static struct V_7 * F_3 ( void * V_8 , T_1 V_5 )
{
void * V_9 = V_8 + V_5 ;
struct V_2 * V_10 = V_8 ;
struct V_4 * V_11 ;
struct V_7 * V_12 ;
T_2 V_13 ;
int V_14 , V_1 ;
if ( ! V_8 )
return NULL ;
if ( V_5 < sizeof( struct V_2 ) )
return F_4 ( - V_15 ) ;
V_13 = F_5 ( V_10 -> V_16 ) ;
if ( V_13 != V_17 ) {
F_6 ( L_1 , V_13 ) ;
return F_4 ( - V_15 ) ;
}
V_8 += sizeof( struct V_2 ) ;
V_1 = F_2 ( V_5 ) ;
if ( V_1 < 0 )
return F_4 ( - V_15 ) ;
if ( V_1 == 0 )
return NULL ;
V_12 = F_7 ( V_1 , V_18 ) ;
if ( ! V_12 )
return F_4 ( - V_19 ) ;
for ( V_14 = 0 ; V_14 < V_1 ; V_14 ++ ) {
V_11 = V_8 ;
if ( V_8 + sizeof( struct V_3 ) > V_9 )
goto V_20;
V_12 -> V_21 [ V_14 ] . V_22 = F_8 ( V_11 -> V_22 ) ;
V_12 -> V_21 [ V_14 ] . V_23 = F_8 ( V_11 -> V_23 ) ;
switch ( V_12 -> V_21 [ V_14 ] . V_22 ) {
case V_24 :
case V_25 :
case V_26 :
case V_27 :
V_8 += sizeof( struct V_3 ) ;
V_12 -> V_21 [ V_14 ] . V_28 = V_29 ;
break;
case V_30 :
case V_31 :
V_8 += sizeof( struct V_4 ) ;
if ( V_8 > V_9 )
goto V_20;
V_12 -> V_21 [ V_14 ] . V_28 = F_5 ( V_11 -> V_28 ) ;
break;
default:
goto V_20;
}
}
if ( V_8 != V_9 )
goto V_20;
return V_12 ;
V_20:
F_9 ( V_12 ) ;
return F_4 ( - V_15 ) ;
}
static void * F_10 ( const struct V_7 * V_12 , T_1 * V_5 )
{
struct V_2 * V_10 ;
struct V_4 * V_11 ;
void * V_32 ;
T_1 V_14 ;
* V_5 = F_1 ( V_12 -> V_33 ) ;
V_10 = F_11 ( sizeof( * V_10 ) + V_12 -> V_33 * sizeof( * V_11 ) , V_18 ) ;
if ( ! V_10 )
return F_4 ( - V_19 ) ;
V_10 -> V_16 = F_12 ( V_17 ) ;
V_32 = V_10 + 1 ;
for ( V_14 = 0 ; V_14 < V_12 -> V_33 ; V_14 ++ ) {
V_11 = V_32 ;
V_11 -> V_22 = F_13 ( V_12 -> V_21 [ V_14 ] . V_22 ) ;
V_11 -> V_23 = F_13 ( V_12 -> V_21 [ V_14 ] . V_23 ) ;
switch( V_12 -> V_21 [ V_14 ] . V_22 ) {
case V_30 :
case V_31 :
V_11 -> V_28 = F_12 ( V_12 -> V_21 [ V_14 ] . V_28 ) ;
V_32 += sizeof( struct V_4 ) ;
break;
case V_24 :
case V_25 :
case V_26 :
case V_27 :
V_32 += sizeof( struct V_3 ) ;
break;
default:
goto V_20;
}
}
return V_10 ;
V_20:
F_14 ( V_10 ) ;
return F_4 ( - V_15 ) ;
}
static struct V_7 * F_15 ( struct V_34 * V_34 , int type )
{
struct V_7 * V_12 ;
char * V_8 = NULL ;
int V_35 , V_36 ;
V_12 = F_16 ( V_34 , type ) ;
if ( V_12 != V_37 )
return V_12 ;
switch ( type ) {
case V_38 :
V_36 = V_39 ;
break;
case V_40 :
V_36 = V_41 ;
break;
default:
F_17 () ;
}
V_35 = F_18 ( V_34 , V_36 , L_2 , NULL , 0 ) ;
if ( V_35 > 0 ) {
V_8 = F_11 ( V_35 , V_18 ) ;
if ( ! V_8 )
return F_4 ( - V_19 ) ;
V_35 = F_18 ( V_34 , V_36 , L_2 , V_8 , V_35 ) ;
}
if ( V_35 > 0 ) {
V_12 = F_3 ( V_8 , V_35 ) ;
} else if ( V_35 == - V_42 || V_35 == - V_43 ) {
V_12 = NULL ;
} else {
V_12 = F_4 ( V_35 ) ;
}
if ( V_8 )
F_14 ( V_8 ) ;
if ( ! F_19 ( V_12 ) )
F_20 ( V_34 , type , V_12 ) ;
return V_12 ;
}
static int F_21 ( struct V_34 * V_34 , int V_36 , struct V_7 * V_12 )
{
char * V_8 = NULL ;
T_1 V_5 = 0 ;
int V_35 ;
if ( V_12 ) {
V_8 = F_10 ( V_12 , & V_5 ) ;
if ( F_19 ( V_8 ) )
return F_22 ( V_8 ) ;
}
V_35 = F_23 ( V_34 , V_36 , L_2 , V_8 , V_5 , 0 ) ;
if ( ! V_8 && V_35 == - V_42 )
V_35 = 0 ;
F_14 ( V_8 ) ;
return V_35 ;
}
static int F_24 ( struct V_34 * V_34 , int type , struct V_7 * V_12 )
{
int V_35 , V_36 ;
if ( F_25 ( V_34 -> V_44 ) )
return - V_45 ;
switch ( type ) {
case V_38 :
V_36 = V_39 ;
if ( V_12 ) {
T_3 V_46 = V_34 -> V_44 ;
V_35 = F_26 ( V_12 , & V_46 ) ;
if ( V_35 < 0 )
return V_35 ;
if ( V_34 -> V_44 != V_46 ) {
struct V_47 V_48 ;
V_48 . V_49 = V_50 | V_51 ;
V_48 . V_52 = V_46 ;
V_48 . V_53 = V_54 ;
V_35 = F_27 ( V_34 , & V_48 ) ;
if ( V_35 < 0 )
return V_35 ;
}
if ( V_35 == 0 )
V_12 = NULL ;
}
break;
case V_40 :
V_36 = V_41 ;
if ( ! F_28 ( V_34 -> V_44 ) )
return V_12 ? - V_55 : 0 ;
break;
default:
return - V_15 ;
}
V_35 = F_21 ( V_34 , V_36 , V_12 ) ;
if ( ! V_35 )
F_20 ( V_34 , type , V_12 ) ;
return V_35 ;
}
int F_29 ( struct V_34 * V_34 , int V_56 , unsigned int V_57 )
{
struct V_7 * V_12 ;
int V_35 ;
if ( V_57 & V_58 )
return - V_59 ;
V_12 = F_15 ( V_34 , V_38 ) ;
if ( F_19 ( V_12 ) )
return F_22 ( V_12 ) ;
if ( V_12 ) {
V_35 = F_30 ( V_34 , V_12 , V_56 ) ;
F_9 ( V_12 ) ;
return V_35 ;
}
return - V_60 ;
}
int F_31 ( struct V_34 * V_61 , struct V_34 * V_34 , int * V_44 )
{
struct V_7 * V_12 , * V_62 ;
int V_35 ;
F_32 ( V_34 ) ;
if ( F_25 ( * V_44 ) )
return 0 ;
V_12 = F_15 ( V_61 , V_40 ) ;
if ( F_19 ( V_12 ) )
return F_22 ( V_12 ) ;
if ( ! V_12 ) {
* V_44 &= ~ F_33 () ;
} else {
if ( F_28 ( * V_44 ) )
F_20 ( V_34 , V_40 , V_12 ) ;
V_62 = F_34 ( V_12 , V_18 ) ;
if ( ! V_62 )
return - V_19 ;
V_35 = F_35 ( V_62 , ( T_3 * ) V_44 ) ;
if ( V_35 < 0 ) {
F_9 ( V_62 ) ;
return V_35 ;
}
if ( V_35 > 0 )
F_20 ( V_34 , V_38 , V_62 ) ;
F_9 ( V_62 ) ;
}
return 0 ;
}
int F_36 ( struct V_34 * V_34 )
{
int V_35 ;
if ( V_34 -> V_63 ) {
V_35 = F_21 ( V_34 , V_41 , V_34 -> V_63 ) ;
if ( V_35 )
return V_35 ;
}
if ( V_34 -> V_64 ) {
V_35 = F_21 ( V_34 , V_39 , V_34 -> V_64 ) ;
if ( V_35 )
return V_35 ;
}
return 0 ;
}
int F_37 ( struct V_34 * V_34 )
{
struct V_7 * V_12 , * V_62 ;
int V_35 ;
if ( F_25 ( V_34 -> V_44 ) )
return - V_45 ;
V_12 = F_15 ( V_34 , V_38 ) ;
if ( F_19 ( V_12 ) || ! V_12 )
return F_22 ( V_12 ) ;
V_62 = F_34 ( V_12 , V_18 ) ;
F_9 ( V_12 ) ;
if ( ! V_62 )
return - V_19 ;
V_35 = F_38 ( V_62 , V_34 -> V_44 ) ;
if ( ! V_35 )
V_35 = F_24 ( V_34 , V_38 , V_62 ) ;
F_9 ( V_62 ) ;
return V_35 ;
}
static T_1 F_39 ( struct V_65 * V_65 , char * V_66 ,
T_1 V_67 , const char * V_68 , T_1 V_69 , int type )
{
const int V_70 = sizeof( V_71 ) ;
if ( V_66 && V_70 <= V_67 )
strcpy ( V_66 , V_71 ) ;
return V_70 ;
}
static T_1 F_40 ( struct V_65 * V_65 , char * V_66 ,
T_1 V_67 , const char * V_68 , T_1 V_69 , int type )
{
const int V_70 = sizeof( V_72 ) ;
if ( V_66 && V_70 <= V_67 )
strcpy ( V_66 , V_72 ) ;
return V_70 ;
}
static int F_41 ( struct V_65 * V_65 , const char * V_68 ,
void * V_73 , T_1 V_5 , int type )
{
struct V_7 * V_12 ;
int V_35 ;
if ( V_68 [ 0 ] != '\0' )
return - V_15 ;
V_12 = F_15 ( V_65 -> V_74 , type ) ;
if ( F_19 ( V_12 ) )
return F_22 ( V_12 ) ;
if ( ! V_12 )
return - V_42 ;
V_35 = F_42 ( V_12 , V_73 , V_5 ) ;
F_9 ( V_12 ) ;
return V_35 ;
}
static int F_43 ( struct V_65 * V_65 , const char * V_68 ,
const void * V_8 , T_1 V_5 , int V_57 , int type )
{
struct V_7 * V_12 ;
int V_35 ;
if ( V_68 [ 0 ] != '\0' )
return - V_15 ;
if ( ! F_44 ( V_65 -> V_74 ) )
return - V_75 ;
if ( V_8 ) {
V_12 = F_45 ( V_8 , V_5 ) ;
if ( F_19 ( V_12 ) )
return F_22 ( V_12 ) ;
if ( V_12 ) {
V_35 = F_46 ( V_12 ) ;
if ( V_35 )
goto V_76;
}
} else {
V_12 = NULL ;
}
V_35 = F_24 ( V_65 -> V_74 , type , V_12 ) ;
V_76:
F_9 ( V_12 ) ;
return V_35 ;
}
