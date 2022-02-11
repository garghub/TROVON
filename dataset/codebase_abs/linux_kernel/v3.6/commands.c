static T_1 F_1 ( T_1 * V_1 , T_1 type )
{
if ( V_1 [ 0 ] != type || V_1 [ 1 ] != V_2 [ V_1 [ 0 ] ] )
return 0 ;
return V_1 [ 2 ] ;
}
static T_2 F_2 ( T_1 * V_1 , T_1 type )
{
if ( V_1 [ 0 ] != type || V_1 [ 1 ] != V_2 [ V_1 [ 0 ] ] )
return 0 ;
return F_3 ( * ( ( V_3 * ) ( V_1 + 2 ) ) ) ;
}
static T_1 F_4 ( T_1 * V_1 )
{
return F_1 ( V_1 , V_4 ) ;
}
static T_2 F_5 ( T_1 * V_1 )
{
return F_2 ( V_1 , V_5 ) & 0x7ff ;
}
static T_2 F_6 ( T_1 * V_1 )
{
return F_2 ( V_1 , V_6 ) ;
}
static T_2 F_7 ( T_1 * V_1 )
{
return F_1 ( V_1 , V_7 ) ;
}
static T_1 F_8 ( T_1 * V_1 )
{
return F_1 ( V_1 , V_8 ) ;
}
static T_1 F_9 ( T_1 * V_1 )
{
return F_1 ( V_1 , V_9 ) & 0xf ;
}
T_1 * F_10 ( T_1 type , T_1 * V_10 , T_1 V_11 , T_1 * V_12 )
{
T_1 * V_1 , V_13 ;
F_11 ( L_1 , type ) ;
if ( type >= V_14 )
return NULL ;
V_13 = V_2 [ type ] ;
if ( V_13 == 0 && V_11 == 0 )
return NULL ;
else if ( V_13 == 0 )
V_13 = V_11 ;
* V_12 = 2 + V_13 ;
V_1 = F_12 ( 2 + V_13 , V_15 ) ;
if ( V_1 == NULL )
return V_1 ;
V_1 [ 0 ] = type ;
V_1 [ 1 ] = V_13 ;
memcpy ( V_1 + 2 , V_10 , V_13 ) ;
return V_1 ;
}
int F_13 ( struct V_16 * V_17 ,
T_1 * V_18 , T_2 V_19 )
{
T_1 * V_1 = V_18 , type , V_13 , V_20 = 0 ;
F_11 ( L_2 , V_19 ) ;
if ( V_17 == NULL )
return - V_21 ;
while ( V_20 < V_19 ) {
type = V_1 [ 0 ] ;
V_13 = V_1 [ 1 ] ;
F_11 ( L_3 , type , V_13 ) ;
switch ( type ) {
case V_4 :
V_17 -> V_22 = F_4 ( V_1 ) ;
break;
case V_5 :
V_17 -> V_23 = F_5 ( V_1 ) + 128 ;
break;
case V_6 :
V_17 -> V_24 = F_6 ( V_1 ) ;
break;
case V_7 :
V_17 -> V_25 = F_7 ( V_1 ) * 10 ;
break;
case V_8 :
V_17 -> V_26 = F_8 ( V_1 ) ;
break;
default:
F_14 ( L_4 , type ) ;
break;
}
V_20 += V_13 + 2 ;
V_1 += V_13 + 2 ;
}
F_11 ( L_5 ,
V_17 -> V_22 , V_17 -> V_23 ,
V_17 -> V_25 , V_17 -> V_26 ,
V_17 -> V_24 ) ;
return 0 ;
}
int F_15 ( struct V_27 * V_28 ,
T_1 * V_18 , T_2 V_19 )
{
T_1 * V_1 = V_18 , type , V_13 , V_20 = 0 ;
F_11 ( L_2 , V_19 ) ;
if ( V_28 == NULL )
return - V_29 ;
while ( V_20 < V_19 ) {
type = V_1 [ 0 ] ;
V_13 = V_1 [ 1 ] ;
F_11 ( L_3 , type , V_13 ) ;
switch ( type ) {
case V_5 :
V_28 -> V_30 = F_5 ( V_1 ) + 128 ;
break;
case V_9 :
V_28 -> V_31 = F_9 ( V_1 ) ;
break;
case V_32 :
break;
default:
F_14 ( L_4 , type ) ;
break;
}
V_20 += V_13 + 2 ;
V_1 += V_13 + 2 ;
}
F_11 ( L_6 , V_28 , V_28 -> V_31 , V_28 -> V_30 ) ;
return 0 ;
}
static struct V_33 * F_16 ( struct V_33 * V_34 ,
T_1 V_35 , T_1 V_36 , T_1 V_37 )
{
T_1 V_38 [ 2 ] ;
F_11 ( L_7 , V_37 , V_35 , V_36 ) ;
V_38 [ 0 ] = ( T_1 ) ( ( V_35 << 2 ) | ( V_37 >> 2 ) ) ;
V_38 [ 1 ] = ( T_1 ) ( ( V_37 << 6 ) | V_36 ) ;
F_11 ( L_8 , V_38 [ 0 ] , V_38 [ 1 ] ) ;
memcpy ( F_17 ( V_34 , V_39 ) , V_38 , V_39 ) ;
return V_34 ;
}
static struct V_33 * F_18 ( struct V_33 * V_34 , T_1 * V_1 ,
T_1 V_12 )
{
if ( V_1 == NULL )
return NULL ;
memcpy ( F_17 ( V_34 , V_12 ) , V_1 , V_12 ) ;
return V_34 ;
}
static struct V_33 * F_19 ( struct V_27 * V_28 ,
T_1 V_40 , T_2 V_41 )
{
struct V_33 * V_42 ;
int V_43 ;
if ( V_28 -> V_36 == 0 )
return NULL ;
V_42 = F_20 ( V_28 -> V_44 , & V_28 -> V_45 , V_46 ,
V_41 + V_39 , & V_43 ) ;
if ( V_42 == NULL ) {
F_14 ( L_9 ) ;
return NULL ;
}
V_42 = F_16 ( V_42 , V_28 -> V_35 , V_28 -> V_36 , V_40 ) ;
return V_42 ;
}
int F_21 ( struct V_27 * V_28 )
{
struct V_33 * V_42 ;
struct V_47 * V_44 ;
struct V_16 * V_17 ;
T_2 V_41 = 0 ;
F_11 ( L_10 ) ;
V_17 = V_28 -> V_17 ;
if ( V_17 == NULL )
return - V_21 ;
V_44 = V_28 -> V_44 ;
if ( V_44 == NULL )
return - V_21 ;
V_41 += V_39 ;
V_41 += V_44 -> V_48 + V_44 -> V_49 + V_50 ;
V_42 = F_22 ( V_41 , V_51 ) ;
if ( V_42 == NULL )
return - V_52 ;
F_23 ( V_42 , V_44 -> V_48 + V_50 ) ;
V_42 = F_16 ( V_42 , V_28 -> V_35 , V_28 -> V_36 , V_53 ) ;
F_24 ( & V_17 -> V_54 , V_42 ) ;
return 0 ;
}
int F_25 ( struct V_47 * V_44 )
{
struct V_33 * V_42 ;
struct V_16 * V_17 ;
T_2 V_41 = 0 ;
F_11 ( L_11 ) ;
V_17 = F_26 ( V_44 ) ;
if ( V_17 == NULL )
return - V_21 ;
V_41 += V_39 ;
V_41 += V_44 -> V_48 + V_44 -> V_49 + V_50 ;
V_42 = F_22 ( V_41 , V_15 ) ;
if ( V_42 == NULL )
return - V_52 ;
F_23 ( V_42 , V_44 -> V_48 + V_50 ) ;
V_42 = F_16 ( V_42 , 0 , 0 , V_55 ) ;
return F_27 ( V_44 , V_17 -> V_56 , V_42 ,
V_57 , V_17 ) ;
}
int F_28 ( struct V_27 * V_28 )
{
struct V_16 * V_17 ;
struct V_33 * V_42 ;
T_1 * V_58 = NULL , V_59 ;
T_1 * V_60 = NULL , V_61 ;
T_1 * V_62 = NULL , V_63 , V_31 ;
V_3 V_64 ;
int V_43 ;
T_2 V_41 = 0 ;
F_11 ( L_12 ) ;
V_17 = V_28 -> V_17 ;
if ( V_17 == NULL )
return - V_21 ;
if ( V_28 -> V_65 != NULL ) {
V_58 = F_10 ( V_32 ,
V_28 -> V_65 ,
V_28 -> V_66 ,
& V_59 ) ;
V_41 += V_59 ;
}
V_64 = F_29 ( V_67 ) ;
V_60 = F_10 ( V_5 , ( T_1 * ) & V_64 , 0 ,
& V_61 ) ;
V_41 += V_61 ;
V_31 = V_68 ;
V_62 = F_10 ( V_9 , & V_31 , 0 , & V_63 ) ;
V_41 += V_63 ;
F_11 ( L_13 , V_41 , V_28 -> V_66 ) ;
V_42 = F_19 ( V_28 , V_69 , V_41 ) ;
if ( V_42 == NULL ) {
V_43 = - V_52 ;
goto V_70;
}
if ( V_58 != NULL )
V_42 = F_18 ( V_42 , V_58 ,
V_59 ) ;
V_42 = F_18 ( V_42 , V_60 , V_61 ) ;
V_42 = F_18 ( V_42 , V_62 , V_63 ) ;
F_24 ( & V_17 -> V_54 , V_42 ) ;
return 0 ;
V_70:
F_14 ( L_14 , V_43 ) ;
F_30 ( V_58 ) ;
F_30 ( V_60 ) ;
F_30 ( V_62 ) ;
return V_43 ;
}
int F_31 ( struct V_27 * V_28 )
{
struct V_16 * V_17 ;
struct V_33 * V_42 ;
T_1 * V_60 = NULL , V_61 ;
T_1 * V_62 = NULL , V_63 , V_31 ;
V_3 V_64 ;
int V_43 ;
T_2 V_41 = 0 ;
F_11 ( L_15 ) ;
V_17 = V_28 -> V_17 ;
if ( V_17 == NULL )
return - V_21 ;
V_64 = F_29 ( V_67 ) ;
V_60 = F_10 ( V_5 , ( T_1 * ) & V_64 , 0 ,
& V_61 ) ;
V_41 += V_61 ;
V_31 = V_68 ;
V_62 = F_10 ( V_9 , & V_31 , 0 , & V_63 ) ;
V_41 += V_63 ;
V_42 = F_19 ( V_28 , V_71 , V_41 ) ;
if ( V_42 == NULL ) {
V_43 = - V_52 ;
goto V_70;
}
V_42 = F_18 ( V_42 , V_60 , V_61 ) ;
V_42 = F_18 ( V_42 , V_62 , V_63 ) ;
F_24 ( & V_17 -> V_54 , V_42 ) ;
return 0 ;
V_70:
F_14 ( L_14 , V_43 ) ;
F_30 ( V_60 ) ;
F_30 ( V_62 ) ;
return V_43 ;
}
int F_32 ( struct V_16 * V_17 , T_1 V_36 , T_1 V_35 , T_1 V_72 )
{
struct V_33 * V_42 ;
struct V_47 * V_44 ;
T_2 V_41 = 1 ;
F_11 ( L_16 , V_72 ) ;
if ( V_17 == NULL )
return - V_21 ;
V_44 = V_17 -> V_44 ;
if ( V_44 == NULL )
return - V_21 ;
V_41 += V_39 ;
V_41 += V_44 -> V_48 + V_44 -> V_49 + V_50 ;
V_42 = F_22 ( V_41 , V_15 ) ;
if ( V_42 == NULL )
return - V_52 ;
F_23 ( V_42 , V_44 -> V_48 + V_50 ) ;
V_42 = F_16 ( V_42 , V_35 , V_36 , V_73 ) ;
memcpy ( F_17 ( V_42 , 1 ) , & V_72 , 1 ) ;
F_33 ( & V_17 -> V_54 , V_42 ) ;
return 0 ;
}
int F_34 ( struct V_27 * V_28 )
{
struct V_33 * V_42 ;
struct V_16 * V_17 ;
F_11 ( L_17 ) ;
V_17 = V_28 -> V_17 ;
if ( V_17 == NULL )
return - V_21 ;
V_42 = F_19 ( V_28 , V_53 , 0 ) ;
if ( V_42 == NULL )
return - V_52 ;
F_33 ( & V_17 -> V_54 , V_42 ) ;
return 0 ;
}
int F_35 ( struct V_27 * V_28 ,
struct V_74 * V_75 , T_3 V_76 )
{
struct V_33 * V_34 ;
struct V_28 * V_45 = & V_28 -> V_45 ;
struct V_16 * V_17 ;
T_3 V_77 = 0 , V_78 ;
T_1 * V_79 , * V_80 ;
F_11 ( L_18 , V_76 ) ;
V_17 = V_28 -> V_17 ;
if ( V_17 == NULL )
return - V_21 ;
V_79 = F_12 ( V_76 , V_15 ) ;
if ( V_79 == NULL )
return - V_52 ;
if ( F_36 ( V_79 , V_75 -> V_81 , V_76 ) ) {
F_30 ( V_79 ) ;
return - V_82 ;
}
V_78 = V_76 ;
V_80 = V_79 ;
while ( V_78 > 0 ) {
V_77 = F_37 ( T_3 , V_28 -> V_30 , V_78 ) ;
F_11 ( L_19 ,
V_77 , V_78 ) ;
V_34 = F_19 ( V_28 , V_83 ,
V_77 + V_84 ) ;
if ( V_34 == NULL )
return - V_52 ;
F_17 ( V_34 , V_84 ) ;
memcpy ( F_17 ( V_34 , V_77 ) , V_80 , V_77 ) ;
F_24 ( & V_28 -> V_54 , V_34 ) ;
F_38 ( V_45 ) ;
F_39 ( V_28 ) ;
F_40 ( V_45 ) ;
V_78 -= V_77 ;
V_80 += V_77 ;
}
F_30 ( V_79 ) ;
return V_76 ;
}
int F_41 ( struct V_27 * V_28 )
{
struct V_33 * V_42 ;
struct V_16 * V_17 ;
F_11 ( L_20 , V_28 -> V_85 ) ;
V_17 = V_28 -> V_17 ;
if ( V_17 == NULL )
return - V_21 ;
V_42 = F_19 ( V_28 , V_86 , V_84 ) ;
if ( V_42 == NULL )
return - V_52 ;
F_17 ( V_42 , V_84 ) ;
V_42 -> V_87 [ 2 ] = V_28 -> V_85 ;
F_33 ( & V_17 -> V_54 , V_42 ) ;
return 0 ;
}
