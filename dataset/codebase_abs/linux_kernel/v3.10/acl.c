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
break;
case V_28 :
V_8 += sizeof( struct V_4 ) ;
if ( V_8 > V_9 )
goto V_20;
V_12 -> V_21 [ V_14 ] . V_29 =
F_9 ( & V_30 ,
F_5 ( V_11 -> V_31 ) ) ;
break;
case V_32 :
V_8 += sizeof( struct V_4 ) ;
if ( V_8 > V_9 )
goto V_20;
V_12 -> V_21 [ V_14 ] . V_33 =
F_10 ( & V_30 ,
F_5 ( V_11 -> V_31 ) ) ;
break;
default:
goto V_20;
}
}
if ( V_8 != V_9 )
goto V_20;
return V_12 ;
V_20:
F_11 ( V_12 ) ;
return F_4 ( - V_15 ) ;
}
static void * F_12 ( const struct V_7 * V_12 , T_1 * V_5 )
{
struct V_2 * V_10 ;
struct V_4 * V_11 ;
void * V_34 ;
T_1 V_14 ;
* V_5 = F_1 ( V_12 -> V_35 ) ;
V_10 = F_13 ( sizeof( * V_10 ) + V_12 -> V_35 * sizeof( * V_11 ) , V_18 ) ;
if ( ! V_10 )
return F_4 ( - V_19 ) ;
V_10 -> V_16 = F_14 ( V_17 ) ;
V_34 = V_10 + 1 ;
for ( V_14 = 0 ; V_14 < V_12 -> V_35 ; V_14 ++ ) {
const struct V_36 * V_37 = & V_12 -> V_21 [ V_14 ] ;
V_11 = V_34 ;
V_11 -> V_22 = F_15 ( V_37 -> V_22 ) ;
V_11 -> V_23 = F_15 ( V_37 -> V_23 ) ;
switch( V_37 -> V_22 ) {
case V_28 :
V_11 -> V_31 = F_14 (
F_16 ( & V_30 , V_37 -> V_29 ) ) ;
V_34 += sizeof( struct V_4 ) ;
break;
case V_32 :
V_11 -> V_31 = F_14 (
F_17 ( & V_30 , V_37 -> V_33 ) ) ;
V_34 += sizeof( struct V_4 ) ;
break;
case V_24 :
case V_25 :
case V_26 :
case V_27 :
V_34 += sizeof( struct V_3 ) ;
break;
default:
goto V_20;
}
}
return V_10 ;
V_20:
F_18 ( V_10 ) ;
return F_4 ( - V_15 ) ;
}
struct V_7 * F_19 ( struct V_38 * V_38 , int type )
{
struct V_7 * V_12 ;
char * V_8 = NULL ;
int V_39 , V_40 ;
V_12 = F_20 ( V_38 , type ) ;
if ( V_12 != V_41 )
return V_12 ;
switch ( type ) {
case V_42 :
V_40 = V_43 ;
break;
case V_44 :
V_40 = V_45 ;
break;
default:
F_21 () ;
}
V_39 = F_22 ( V_38 , V_40 , L_2 , NULL , 0 ) ;
if ( V_39 > 0 ) {
V_8 = F_13 ( V_39 , V_18 ) ;
if ( ! V_8 )
return F_4 ( - V_19 ) ;
V_39 = F_22 ( V_38 , V_40 , L_2 , V_8 , V_39 ) ;
}
if ( V_39 > 0 ) {
V_12 = F_3 ( V_8 , V_39 ) ;
} else if ( V_39 == - V_46 || V_39 == - V_47 ) {
V_12 = NULL ;
} else {
V_12 = F_4 ( V_39 ) ;
}
if ( V_8 )
F_18 ( V_8 ) ;
if ( ! F_23 ( V_12 ) )
F_24 ( V_38 , type , V_12 ) ;
return V_12 ;
}
static int F_25 ( struct V_38 * V_38 , int V_40 , struct V_7 * V_12 )
{
char * V_8 = NULL ;
T_1 V_5 = 0 ;
int V_39 ;
if ( V_12 ) {
V_8 = F_12 ( V_12 , & V_5 ) ;
if ( F_23 ( V_8 ) )
return F_26 ( V_8 ) ;
}
V_39 = F_27 ( V_38 , V_40 , L_2 , V_8 , V_5 , 0 ) ;
if ( ! V_8 && V_39 == - V_46 )
V_39 = 0 ;
F_18 ( V_8 ) ;
return V_39 ;
}
static int F_28 ( struct V_38 * V_38 , int type , struct V_7 * V_12 )
{
int V_39 , V_40 ;
if ( F_29 ( V_38 -> V_48 ) )
return - V_49 ;
switch ( type ) {
case V_42 :
V_40 = V_43 ;
if ( V_12 ) {
T_3 V_50 = V_38 -> V_48 ;
V_39 = F_30 ( V_12 , & V_50 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( V_38 -> V_48 != V_50 ) {
struct V_51 V_52 ;
V_52 . V_53 = V_54 | V_55 ;
V_52 . V_56 = V_50 ;
V_52 . V_57 = V_58 ;
V_39 = F_31 ( V_38 , & V_52 ) ;
if ( V_39 < 0 )
return V_39 ;
}
if ( V_39 == 0 )
V_12 = NULL ;
}
break;
case V_44 :
V_40 = V_45 ;
if ( ! F_32 ( V_38 -> V_48 ) )
return V_12 ? - V_59 : 0 ;
break;
default:
return - V_15 ;
}
V_39 = F_25 ( V_38 , V_40 , V_12 ) ;
if ( ! V_39 )
F_24 ( V_38 , type , V_12 ) ;
return V_39 ;
}
int F_33 ( struct V_38 * V_60 , struct V_38 * V_38 , T_3 * V_48 )
{
struct V_7 * V_12 ;
int V_39 ;
F_34 ( V_38 ) ;
if ( F_29 ( * V_48 ) )
return 0 ;
V_12 = F_19 ( V_60 , V_44 ) ;
if ( F_23 ( V_12 ) )
return F_26 ( V_12 ) ;
if ( ! V_12 ) {
* V_48 &= ~ F_35 () ;
} else {
if ( F_32 ( * V_48 ) )
F_24 ( V_38 , V_44 , V_12 ) ;
V_39 = F_36 ( & V_12 , V_18 , V_48 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( V_39 > 0 )
F_24 ( V_38 , V_42 , V_12 ) ;
F_11 ( V_12 ) ;
}
return 0 ;
}
int F_37 ( struct V_38 * V_38 )
{
int V_39 ;
if ( V_38 -> V_61 ) {
V_39 = F_25 ( V_38 , V_45 , V_38 -> V_61 ) ;
if ( V_39 )
return V_39 ;
}
if ( V_38 -> V_62 ) {
V_39 = F_25 ( V_38 , V_43 , V_38 -> V_62 ) ;
if ( V_39 )
return V_39 ;
}
return 0 ;
}
int F_38 ( struct V_38 * V_38 )
{
struct V_7 * V_12 ;
int V_39 ;
if ( F_29 ( V_38 -> V_48 ) )
return - V_49 ;
V_12 = F_19 ( V_38 , V_42 ) ;
if ( F_23 ( V_12 ) || ! V_12 )
return F_26 ( V_12 ) ;
V_39 = F_39 ( & V_12 , V_18 , V_38 -> V_48 ) ;
if ( V_39 )
return V_39 ;
V_39 = F_28 ( V_38 , V_42 , V_12 ) ;
F_11 ( V_12 ) ;
return V_39 ;
}
static T_1 F_40 ( struct V_63 * V_63 , char * V_64 ,
T_1 V_65 , const char * V_66 , T_1 V_67 , int type )
{
const int V_68 = sizeof( V_69 ) ;
if ( V_64 && V_68 <= V_65 )
strcpy ( V_64 , V_69 ) ;
return V_68 ;
}
static T_1 F_41 ( struct V_63 * V_63 , char * V_64 ,
T_1 V_65 , const char * V_66 , T_1 V_67 , int type )
{
const int V_68 = sizeof( V_70 ) ;
if ( V_64 && V_68 <= V_65 )
strcpy ( V_64 , V_70 ) ;
return V_68 ;
}
static int F_42 ( struct V_63 * V_63 , const char * V_66 ,
void * V_71 , T_1 V_5 , int type )
{
struct V_7 * V_12 ;
int V_39 ;
if ( V_66 [ 0 ] != '\0' )
return - V_15 ;
V_12 = F_19 ( V_63 -> V_72 , type ) ;
if ( F_23 ( V_12 ) )
return F_26 ( V_12 ) ;
if ( ! V_12 )
return - V_46 ;
V_39 = F_43 ( & V_30 , V_12 , V_71 , V_5 ) ;
F_11 ( V_12 ) ;
return V_39 ;
}
static int F_44 ( struct V_63 * V_63 , const char * V_66 ,
const void * V_8 , T_1 V_5 , int V_73 , int type )
{
struct V_7 * V_12 ;
int V_39 ;
if ( V_66 [ 0 ] != '\0' )
return - V_15 ;
if ( ! F_45 ( V_63 -> V_72 ) )
return - V_74 ;
if ( V_8 ) {
V_12 = F_46 ( & V_30 , V_8 , V_5 ) ;
if ( F_23 ( V_12 ) )
return F_26 ( V_12 ) ;
if ( V_12 ) {
V_39 = F_47 ( V_12 ) ;
if ( V_39 )
goto V_75;
}
} else {
V_12 = NULL ;
}
V_39 = F_28 ( V_63 -> V_72 , type , V_12 ) ;
V_75:
F_11 ( V_12 ) ;
return V_39 ;
}
