static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_10 * V_10 = F_4 ( V_4 ) ;
unsigned int V_11 ;
int V_12 [ 2 ] ;
int V_13 ;
V_13 = F_5 ( V_9 -> V_14 [ V_10 -> V_15 ] , & V_11 ) ;
if ( V_13 )
return V_13 ;
if ( V_11 >= V_10 -> V_16 )
return - V_17 ;
V_12 [ 0 ] = V_10 -> V_18 [ V_11 ] . integer ;
V_12 [ 1 ] = V_10 -> V_18 [ V_11 ] . V_19 ;
return F_6 ( V_5 , V_20 , 2 , V_12 ) ;
}
static T_1 F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_21 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_10 * V_10 = F_4 ( V_4 ) ;
int V_22 , integer , V_19 , V_13 ;
V_13 = F_8 ( V_5 , 100000 , & integer , & V_19 ) ;
if ( V_13 )
return V_13 ;
for ( V_22 = 0 ; V_22 < V_10 -> V_16 ; V_22 ++ )
if ( V_10 -> V_18 [ V_22 ] . integer == integer &&
V_10 -> V_18 [ V_22 ] . V_19 == V_19 )
break;
if ( V_22 == V_10 -> V_16 )
return - V_17 ;
V_13 = F_9 ( V_9 -> V_14 [ V_10 -> V_15 ] , V_22 ) ;
if ( V_13 )
return V_13 ;
return V_21 ;
}
static int F_10 ( struct V_6 * V_7 ,
struct V_23 const * V_24 ,
int * V_22 , int * V_25 , long V_26 )
{
struct V_8 * V_9 = F_3 ( V_7 ) ;
unsigned int V_27 = V_28 [ V_24 -> V_29 ] ;
unsigned int V_30 = V_31 [ V_24 -> V_29 ] ;
unsigned int V_32 = V_33 [ V_24 -> V_29 ] ;
int V_13 ;
switch ( V_24 -> type ) {
case V_34 :
switch ( V_26 ) {
case V_35 :
V_13 = F_11 ( V_9 -> V_36 , V_27 , V_22 ) ;
if ( V_13 )
return V_13 ;
return V_37 ;
case V_38 :
V_13 = F_5 ( V_9 -> V_14 [ V_32 ] , V_22 ) ;
if ( V_13 )
return V_13 ;
return V_37 ;
}
break;
case V_39 :
switch ( V_26 ) {
case V_35 :
V_13 = F_5 ( V_9 -> V_14 [ V_30 ] , V_22 ) ;
if ( V_13 )
return V_13 ;
return V_37 ;
case V_40 :
* V_22 = 0 ;
* V_25 = 800000 ;
return V_20 ;
}
break;
default:
break;
}
return - V_17 ;
}
static int F_12 ( struct V_6 * V_7 ,
struct V_23 const * V_24 ,
int V_22 , int V_25 , long V_26 )
{
struct V_8 * V_9 = F_3 ( V_7 ) ;
unsigned int V_30 = V_31 [ V_24 -> V_29 ] ;
unsigned int V_32 = V_33 [ V_24 -> V_29 ] ;
switch ( V_24 -> type ) {
case V_34 :
switch ( V_26 ) {
case V_38 :
return F_9 ( V_9 -> V_14 [ V_32 ] , V_22 ) ;
}
break;
case V_39 :
switch ( V_26 ) {
case V_35 :
return F_9 ( V_9 -> V_14 [ V_30 ] , V_22 ) ;
}
break;
default:
break;
}
return - V_17 ;
}
static T_3 F_13 ( int V_41 , void * V_42 )
{
struct V_43 * V_44 = V_42 ;
struct V_6 * V_7 = V_44 -> V_7 ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
int V_13 , V_45 , V_46 = 0 ;
T_4 V_47 [ 10 ] ;
F_14 (bit, indio_dev->active_scan_mask,
indio_dev->masklength) {
V_13 = F_11 ( V_9 -> V_36 , V_28 [ V_45 ] ,
& V_47 [ V_46 ++ ] ) ;
if ( V_13 )
goto V_48;
}
F_15 ( V_7 , V_47 , V_44 -> V_49 ) ;
V_48:
F_16 ( V_7 -> V_50 ) ;
return V_51 ;
}
static int T_5 F_17 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
int V_13 ;
V_13 = F_18 ( V_9 -> V_36 , V_52 ,
V_53 ,
V_53 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_19 ( V_9 -> V_54 ) ;
if ( V_13 ) {
F_20 ( V_2 , L_1 ) ;
return V_13 ;
}
return 0 ;
}
static int T_5 F_21 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
int V_13 ;
V_13 = F_22 ( V_9 -> V_54 ) ;
if ( V_13 ) {
F_20 ( V_2 , L_2 ) ;
return V_13 ;
}
V_13 = F_18 ( V_9 -> V_36 , V_52 ,
V_53 , 0 ) ;
if ( V_13 )
return V_13 ;
return 0 ;
}
static int F_23 ( struct V_55 * V_56 ,
const struct V_57 * V_58 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
int V_46 , V_13 ;
V_7 = F_24 ( & V_56 -> V_2 , sizeof( * V_9 ) ) ;
if ( ! V_7 )
return - V_59 ;
V_9 = F_3 ( V_7 ) ;
F_25 ( V_56 , V_7 ) ;
V_9 -> V_2 = & V_56 -> V_2 ;
V_9 -> V_41 = V_56 -> V_41 ;
V_9 -> V_36 = F_26 ( V_56 , & V_60 ) ;
if ( F_27 ( V_9 -> V_36 ) ) {
F_20 ( V_9 -> V_2 , L_3 ) ;
return F_28 ( V_9 -> V_36 ) ;
}
for ( V_46 = 0 ; V_46 < V_61 ; V_46 ++ ) {
V_9 -> V_14 [ V_46 ] = F_29 ( V_9 -> V_2 , V_9 -> V_36 ,
V_62 [ V_46 ] ) ;
if ( F_27 ( V_9 -> V_14 [ V_46 ] ) ) {
F_20 ( V_9 -> V_2 , L_4 ) ;
return F_28 ( V_9 -> V_14 [ V_46 ] ) ;
}
}
V_9 -> V_54 = F_30 ( V_9 -> V_2 , L_5 ) ;
if ( F_27 ( V_9 -> V_54 ) ) {
F_20 ( V_9 -> V_2 , L_6 ) ;
return F_28 ( V_9 -> V_54 ) ;
}
V_13 = F_22 ( V_9 -> V_54 ) ;
if ( V_13 ) {
F_20 ( V_9 -> V_2 , L_2 ) ;
return V_13 ;
}
V_13 = F_31 ( V_9 -> V_36 , V_63 ,
V_64 ) ;
if ( V_13 ) {
F_20 ( V_9 -> V_2 , L_7 ) ;
goto V_65;
}
V_13 = F_32 ( V_9 -> V_36 , V_66 ,
F_33 ( V_66 ) ) ;
if ( V_13 ) {
F_20 ( V_9 -> V_2 , L_8 ) ;
goto V_65;
}
V_7 -> V_67 = V_68 ;
V_7 -> V_2 . V_69 = V_9 -> V_2 ;
V_7 -> V_70 = V_71 ;
V_7 -> V_72 = F_33 ( V_71 ) ;
V_7 -> V_73 = V_74 ;
V_7 -> V_75 = & V_76 ;
if ( V_9 -> V_41 > 0 ) {
V_9 -> V_50 = F_34 ( V_9 -> V_2 ,
L_9 ,
V_7 -> V_73 ,
V_7 -> V_58 ) ;
if ( ! V_9 -> V_50 ) {
F_20 ( V_9 -> V_2 , L_10 ) ;
V_13 = - V_59 ;
goto V_65;
}
F_35 ( V_9 -> V_50 , V_7 ) ;
V_9 -> V_50 -> V_77 = & V_78 ;
V_9 -> V_50 -> V_2 . V_69 = V_9 -> V_2 ;
V_13 = F_36 ( V_9 -> V_50 ) ;
if ( V_13 ) {
F_20 ( V_9 -> V_2 , L_11 ) ;
goto V_65;
}
V_13 = F_37 ( V_9 -> V_2 , V_9 -> V_41 ,
V_79 ,
NULL , V_80 ,
V_74 ,
V_9 -> V_50 ) ;
if ( V_13 ) {
F_20 ( V_9 -> V_2 , L_12 ) ;
goto V_65;
}
}
V_13 = F_38 ( V_7 , & V_81 ,
F_13 , NULL ) ;
if ( V_13 ) {
F_20 ( V_9 -> V_2 , L_13 ) ;
goto V_82;
}
V_13 = F_39 ( V_7 ) ;
if ( V_13 ) {
F_20 ( V_9 -> V_2 , L_14 ) ;
goto V_83;
}
return 0 ;
V_83:
F_40 ( V_7 ) ;
V_82:
if ( V_9 -> V_41 > 0 )
F_41 ( V_9 -> V_50 ) ;
V_65:
F_19 ( V_9 -> V_54 ) ;
return V_13 ;
}
static int F_42 ( struct V_55 * V_56 )
{
struct V_6 * V_7 = F_43 ( V_56 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
int V_13 ;
F_44 ( V_7 ) ;
F_40 ( V_7 ) ;
if ( V_9 -> V_41 > 0 )
F_41 ( V_9 -> V_50 ) ;
V_13 = F_19 ( V_9 -> V_54 ) ;
if ( V_13 ) {
F_20 ( V_9 -> V_2 , L_1 ) ;
return V_13 ;
}
return 0 ;
}
