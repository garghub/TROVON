static int F_1 ( struct V_1 * V_2 , T_1 V_3 , int V_4 )
{
unsigned int V_5 = V_2 -> V_6 >> 2 ;
V_4 = V_2 -> V_7 - V_4 - 1 ;
while ( V_4 -- )
V_3 /= V_5 ;
return V_3 % V_5 ;
}
static int F_2 ( struct V_1 * V_2 , struct V_8 V_9 , int V_4 )
{
T_1 V_3 = F_3 ( & V_10 , V_9 ) ;
return F_1 ( V_2 , V_3 , V_4 ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
return ( V_2 -> V_6 - sizeof( struct V_11 ) )
/ V_2 -> V_12 ;
}
static char * F_5 ( T_2 V_13 )
{
char * V_14 = F_6 ( V_13 , V_15 ) ;
if ( ! V_14 )
F_7 ( V_16
L_1 ) ;
return V_14 ;
}
static T_3 F_8 ( struct V_1 * V_2 , T_4 V_17 , char * V_14 )
{
struct V_18 * V_19 = V_2 -> V_20 ;
memset ( V_14 , 0 , V_2 -> V_6 ) ;
return V_19 -> V_21 -> V_22 ( V_19 , V_2 -> V_23 , V_14 ,
V_2 -> V_6 , V_17 << V_2 -> V_24 ) ;
}
static T_3 F_9 ( struct V_1 * V_2 , T_4 V_17 , char * V_14 )
{
struct V_18 * V_19 = V_2 -> V_20 ;
T_3 V_25 ;
V_25 = V_19 -> V_21 -> V_26 ( V_19 , V_2 -> V_23 , V_14 ,
V_2 -> V_6 , V_17 << V_2 -> V_24 ) ;
if ( V_25 != V_2 -> V_6 ) {
F_10 ( V_19 , L_2 ) ;
if ( V_25 >= 0 )
V_25 = - V_27 ;
}
return V_25 ;
}
static int F_11 ( struct V_1 * V_2 )
{
char * V_14 = F_5 ( V_2 -> V_6 ) ;
struct V_11 * V_28 = (struct V_11 * ) V_14 ;
int V_25 , V_17 ;
if ( ! V_14 )
return - V_29 ;
if ( V_2 -> V_30 ) {
V_17 = V_2 -> V_30 ;
V_25 = F_8 ( V_2 , V_17 , V_14 ) ;
if ( V_25 < 0 )
goto V_31;
V_2 -> V_30 = F_12 ( V_28 -> V_32 ) ;
}
else {
memset ( V_14 , 0 , V_2 -> V_6 ) ;
V_25 = F_9 ( V_2 , V_2 -> V_33 , V_14 ) ;
if ( V_25 < 0 )
goto V_31;
V_17 = V_2 -> V_33 ++ ;
}
F_13 ( V_2 -> V_20 , V_2 -> V_23 ) ;
V_25 = V_17 ;
V_31:
F_14 ( V_14 ) ;
return V_25 ;
}
static int F_15 ( struct V_1 * V_2 , char * V_14 , T_4 V_17 )
{
struct V_11 * V_28 = (struct V_11 * ) V_14 ;
int V_34 ;
V_28 -> V_32 = F_16 ( V_2 -> V_30 ) ;
V_28 -> V_35 = F_16 ( 0 ) ;
V_28 -> V_36 = F_17 ( 0 ) ;
V_34 = F_9 ( V_2 , V_17 , V_14 ) ;
if ( V_34 < 0 )
return V_34 ;
V_2 -> V_30 = V_17 ;
F_13 ( V_2 -> V_20 , V_2 -> V_23 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , char * V_14 ,
T_4 V_17 )
{
char * V_37 = F_5 ( V_2 -> V_6 ) ;
struct V_11 * V_28 = (struct V_11 * ) V_14 ;
T_4 V_38 = F_12 ( V_28 -> V_32 ) ;
T_4 V_39 = F_12 ( V_28 -> V_35 ) ;
int V_34 ;
if ( ! V_37 )
return - V_29 ;
if ( V_38 ) {
V_34 = F_8 ( V_2 , V_38 , V_37 ) ;
if ( V_34 < 0 )
goto V_31;
( (struct V_11 * ) V_37 ) -> V_35 =
V_28 -> V_35 ;
V_34 = F_9 ( V_2 , V_38 , V_37 ) ;
if ( V_34 < 0 )
goto V_31;
}
if ( V_39 ) {
V_34 = F_8 ( V_2 , V_39 , V_37 ) ;
if ( V_34 < 0 )
goto V_31;
( (struct V_11 * ) V_37 ) -> V_32 =
V_28 -> V_32 ;
V_34 = F_9 ( V_2 , V_39 , V_37 ) ;
if ( V_34 < 0 )
goto V_31;
} else {
V_2 -> V_40 = V_38 ;
F_13 ( V_2 -> V_20 , V_2 -> V_23 ) ;
}
F_14 ( V_37 ) ;
V_28 -> V_32 = V_28 -> V_35 = F_16 ( 0 ) ;
if ( F_9 ( V_2 , V_17 , V_14 ) < 0 )
F_10 ( V_2 -> V_20 , L_3
L_4 , V_17 ) ;
return 0 ;
V_31:
F_14 ( V_37 ) ;
return V_34 ;
}
static int F_19 ( struct V_1 * V_2 , char * V_14 ,
T_4 V_17 )
{
char * V_37 = F_5 ( V_2 -> V_6 ) ;
struct V_11 * V_28 = (struct V_11 * ) V_14 ;
int V_34 ;
if ( ! V_37 )
return - V_29 ;
V_28 -> V_32 = F_16 ( V_2 -> V_40 ) ;
V_28 -> V_35 = F_16 ( 0 ) ;
V_34 = F_9 ( V_2 , V_17 , V_14 ) ;
if ( V_34 < 0 )
goto V_31;
if ( V_2 -> V_40 ) {
V_34 = F_8 ( V_2 , V_2 -> V_40 , V_37 ) ;
if ( V_34 < 0 )
goto V_31;
( (struct V_11 * ) V_37 ) -> V_35 =
F_16 ( V_17 ) ;
V_34 = F_9 ( V_2 , V_2 -> V_40 , V_37 ) ;
if ( V_34 < 0 )
goto V_31;
}
F_14 ( V_37 ) ;
V_2 -> V_40 = V_17 ;
F_13 ( V_2 -> V_20 , V_2 -> V_23 ) ;
return 0 ;
V_31:
F_14 ( V_37 ) ;
return V_34 ;
}
int F_20 ( struct V_1 * V_2 , char * V_41 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_2 -> V_12 ; V_42 ++ )
if ( V_41 [ V_42 ] )
return 0 ;
return 1 ;
}
static T_4 F_21 ( struct V_1 * V_2 ,
struct V_43 * V_43 , int * V_34 )
{
T_4 V_17 , V_42 ;
struct V_11 * V_28 ;
char * V_14 = F_5 ( V_2 -> V_6 ) ;
char * V_44 ;
* V_34 = 0 ;
if ( ! V_14 ) {
* V_34 = - V_29 ;
return 0 ;
}
V_28 = (struct V_11 * ) V_14 ;
if ( V_2 -> V_40 ) {
V_17 = V_2 -> V_40 ;
* V_34 = F_8 ( V_2 , V_17 , V_14 ) ;
if ( * V_34 < 0 )
goto V_31;
} else {
V_17 = F_11 ( V_2 ) ;
if ( ( int ) V_17 < 0 ) {
* V_34 = V_17 ;
F_14 ( V_14 ) ;
return 0 ;
}
memset ( V_14 , 0 , V_2 -> V_6 ) ;
V_2 -> V_40 = V_17 ;
F_13 ( V_43 -> V_45 , V_43 -> V_46 . type ) ;
}
if ( F_22 ( V_28 -> V_36 ) + 1 >= F_4 ( V_2 ) ) {
* V_34 = F_18 ( V_2 , V_14 , V_17 ) ;
if ( * V_34 < 0 ) {
F_10 ( V_43 -> V_45 , L_5
L_6 , V_17 ) ;
goto V_31;
}
}
F_23 ( & V_28 -> V_36 , 1 ) ;
V_44 = V_14 + sizeof( struct V_11 ) ;
for ( V_42 = 0 ; V_42 < F_4 ( V_2 ) ; V_42 ++ ) {
if ( F_20 ( V_2 , V_44 ) )
break;
V_44 += V_2 -> V_12 ;
}
#ifdef F_24
if ( V_42 == F_4 ( V_2 ) ) {
F_10 ( V_43 -> V_45 , L_7 ) ;
* V_34 = - V_27 ;
goto V_31;
}
#endif
* V_34 = F_9 ( V_2 , V_17 , V_14 ) ;
if ( * V_34 < 0 ) {
F_10 ( V_43 -> V_45 , L_8 ,
V_17 ) ;
goto V_31;
}
V_43 -> V_47 = ( V_17 << V_2 -> V_24 ) +
sizeof( struct V_11 ) +
V_42 * V_2 -> V_12 ;
F_14 ( V_14 ) ;
return V_17 ;
V_31:
F_14 ( V_14 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 , struct V_43 * V_43 ,
T_4 * V_48 , int V_4 )
{
char * V_14 = F_5 ( V_2 -> V_6 ) ;
int V_25 = 0 , V_49 = 0 , V_50 = 0 ;
T_5 * V_51 ;
T_4 V_52 ;
if ( ! V_14 )
return - V_29 ;
if ( ! * V_48 ) {
V_25 = F_11 ( V_2 ) ;
if ( V_25 < 0 )
goto V_31;
* V_48 = V_25 ;
memset ( V_14 , 0 , V_2 -> V_6 ) ;
V_50 = 1 ;
} else {
V_25 = F_8 ( V_2 , * V_48 , V_14 ) ;
if ( V_25 < 0 ) {
F_10 ( V_43 -> V_45 , L_9
L_10 , * V_48 ) ;
goto V_31;
}
}
V_51 = ( T_5 * ) V_14 ;
V_52 = F_12 ( V_51 [ F_2 ( V_2 , V_43 -> V_46 , V_4 ) ] ) ;
if ( ! V_52 )
V_49 = 1 ;
if ( V_4 == V_2 -> V_7 - 1 ) {
#ifdef F_24
if ( V_52 ) {
F_10 ( V_43 -> V_45 , L_11
L_12 ,
F_12 ( V_51 [ F_2 ( V_2 ,
V_43 -> V_46 , V_4 ) ] ) ) ;
V_25 = - V_27 ;
goto V_31;
}
#endif
V_52 = F_21 ( V_2 , V_43 , & V_25 ) ;
} else {
V_25 = F_25 ( V_2 , V_43 , & V_52 , V_4 + 1 ) ;
}
if ( V_49 && V_25 >= 0 ) {
V_51 [ F_2 ( V_2 , V_43 -> V_46 , V_4 ) ] =
F_16 ( V_52 ) ;
V_25 = F_9 ( V_2 , * V_48 , V_14 ) ;
} else if ( V_50 && V_25 < 0 ) {
F_15 ( V_2 , V_14 , * V_48 ) ;
}
V_31:
F_14 ( V_14 ) ;
return V_25 ;
}
static inline int F_26 ( struct V_1 * V_2 ,
struct V_43 * V_43 )
{
int V_53 = V_54 ;
#ifdef F_24
if ( V_2 -> V_33 <= V_54 ) {
F_10 ( V_43 -> V_45 , L_13 ) ;
return - V_27 ;
}
#endif
return F_25 ( V_2 , V_43 , & V_53 , 0 ) ;
}
int F_27 ( struct V_1 * V_2 , struct V_43 * V_43 )
{
int type = V_43 -> V_46 . type ;
struct V_18 * V_19 = V_43 -> V_45 ;
T_3 V_25 ;
char * V_44 = F_5 ( V_2 -> V_12 ) ;
if ( ! V_44 )
return - V_29 ;
if ( ! V_43 -> V_47 ) {
V_25 = F_26 ( V_2 , V_43 ) ;
if ( V_25 < 0 ) {
F_10 ( V_19 , L_14
L_15 , V_25 ) ;
F_14 ( V_44 ) ;
return V_25 ;
}
}
F_28 ( & V_43 -> V_55 ) ;
V_2 -> V_56 -> V_57 ( V_44 , V_43 ) ;
F_29 ( & V_43 -> V_55 ) ;
V_25 = V_19 -> V_21 -> V_26 ( V_19 , type , V_44 , V_2 -> V_12 ,
V_43 -> V_47 ) ;
if ( V_25 != V_2 -> V_12 ) {
F_10 ( V_19 , L_2 ) ;
if ( V_25 >= 0 )
V_25 = - V_58 ;
} else {
V_25 = 0 ;
}
F_30 ( V_59 ) ;
F_14 ( V_44 ) ;
return V_25 ;
}
static int F_31 ( struct V_1 * V_2 , struct V_43 * V_43 ,
T_4 V_17 )
{
struct V_11 * V_28 ;
char * V_14 = F_5 ( V_2 -> V_6 ) ;
int V_25 = 0 ;
if ( ! V_14 )
return - V_29 ;
if ( V_43 -> V_47 >> V_2 -> V_24 != V_17 ) {
F_10 ( V_43 -> V_45 , L_16
L_17 , V_17 ,
( T_4 ) ( V_43 -> V_47 >> V_2 -> V_24 ) ) ;
goto V_31;
}
V_25 = F_8 ( V_2 , V_17 , V_14 ) ;
if ( V_25 < 0 ) {
F_10 ( V_43 -> V_45 , L_18 ,
V_17 ) ;
goto V_31;
}
V_28 = (struct V_11 * ) V_14 ;
F_23 ( & V_28 -> V_36 , - 1 ) ;
if ( ! F_22 ( V_28 -> V_36 ) ) {
V_25 = F_18 ( V_2 , V_14 , V_17 ) ;
if ( V_25 >= 0 )
V_25 = F_15 ( V_2 , V_14 , V_17 ) ;
if ( V_25 < 0 ) {
F_10 ( V_43 -> V_45 , L_19
L_20 , V_17 ) ;
goto V_31;
}
} else {
memset ( V_14 +
( V_43 -> V_47 & ( ( 1 << V_2 -> V_24 ) - 1 ) ) ,
0 , V_2 -> V_12 ) ;
if ( F_22 ( V_28 -> V_36 ) ==
F_4 ( V_2 ) - 1 ) {
V_25 = F_19 ( V_2 , V_14 , V_17 ) ;
if ( V_25 < 0 ) {
F_10 ( V_43 -> V_45 , L_21
L_22 , V_17 ) ;
goto V_31;
}
} else {
V_25 = F_9 ( V_2 , V_17 , V_14 ) ;
if ( V_25 < 0 ) {
F_10 ( V_43 -> V_45 , L_23
L_24 , V_17 ) ;
goto V_31;
}
}
}
V_43 -> V_47 = 0 ;
V_31:
F_14 ( V_14 ) ;
return V_25 ;
}
static int F_32 ( struct V_1 * V_2 , struct V_43 * V_43 ,
T_4 * V_17 , int V_4 )
{
char * V_14 = F_5 ( V_2 -> V_6 ) ;
int V_25 = 0 ;
T_4 V_52 ;
T_5 * V_51 = ( T_5 * ) V_14 ;
if ( ! V_14 )
return - V_29 ;
V_25 = F_8 ( V_2 , * V_17 , V_14 ) ;
if ( V_25 < 0 ) {
F_10 ( V_43 -> V_45 , L_18 ,
* V_17 ) ;
goto V_31;
}
V_52 = F_12 ( V_51 [ F_2 ( V_2 , V_43 -> V_46 , V_4 ) ] ) ;
if ( V_4 == V_2 -> V_7 - 1 ) {
V_25 = F_31 ( V_2 , V_43 , V_52 ) ;
V_52 = 0 ;
} else {
V_25 = F_32 ( V_2 , V_43 , & V_52 , V_4 + 1 ) ;
}
if ( V_25 >= 0 && ! V_52 ) {
int V_42 ;
V_51 [ F_2 ( V_2 , V_43 -> V_46 , V_4 ) ] = F_16 ( 0 ) ;
for ( V_42 = 0 ; V_42 < ( V_2 -> V_6 >> 2 ) && ! V_51 [ V_42 ] ; V_42 ++ )
;
if ( V_42 == ( V_2 -> V_6 >> 2 )
&& * V_17 != V_54 ) {
F_15 ( V_2 , V_14 , * V_17 ) ;
* V_17 = 0 ;
} else {
V_25 = F_9 ( V_2 , * V_17 , V_14 ) ;
if ( V_25 < 0 )
F_10 ( V_43 -> V_45 ,
L_25 ,
* V_17 ) ;
}
}
V_31:
F_14 ( V_14 ) ;
return V_25 ;
}
int F_33 ( struct V_1 * V_2 , struct V_43 * V_43 )
{
T_4 V_53 = V_54 ;
if ( ! V_43 -> V_47 )
return 0 ;
return F_32 ( V_2 , V_43 , & V_53 , 0 ) ;
}
static T_6 F_34 ( struct V_1 * V_2 ,
struct V_43 * V_43 , T_4 V_17 )
{
char * V_14 = F_5 ( V_2 -> V_6 ) ;
T_6 V_25 = 0 ;
int V_42 ;
char * V_44 ;
if ( ! V_14 )
return - V_29 ;
V_25 = F_8 ( V_2 , V_17 , V_14 ) ;
if ( V_25 < 0 ) {
F_10 ( V_43 -> V_45 , L_26
L_10 , V_17 ) ;
goto V_31;
}
V_44 = V_14 + sizeof( struct V_11 ) ;
for ( V_42 = 0 ; V_42 < F_4 ( V_2 ) ; V_42 ++ ) {
if ( V_2 -> V_56 -> V_60 ( V_44 , V_43 ) )
break;
V_44 += V_2 -> V_12 ;
}
if ( V_42 == F_4 ( V_2 ) ) {
F_10 ( V_43 -> V_45 ,
L_27 ,
F_3 ( & V_10 , V_43 -> V_46 ) ) ;
V_25 = - V_27 ;
goto V_31;
} else {
V_25 = ( V_17 << V_2 -> V_24 ) + sizeof( struct
V_11 ) + V_42 * V_2 -> V_12 ;
}
V_31:
F_14 ( V_14 ) ;
return V_25 ;
}
static T_6 F_35 ( struct V_1 * V_2 ,
struct V_43 * V_43 , T_4 V_17 , int V_4 )
{
char * V_14 = F_5 ( V_2 -> V_6 ) ;
T_6 V_25 = 0 ;
T_5 * V_51 = ( T_5 * ) V_14 ;
if ( ! V_14 )
return - V_29 ;
V_25 = F_8 ( V_2 , V_17 , V_14 ) ;
if ( V_25 < 0 ) {
F_10 ( V_43 -> V_45 , L_28 ,
V_17 ) ;
goto V_31;
}
V_25 = 0 ;
V_17 = F_12 ( V_51 [ F_2 ( V_2 , V_43 -> V_46 , V_4 ) ] ) ;
if ( ! V_17 )
goto V_31;
if ( V_4 < V_2 -> V_7 - 1 )
V_25 = F_35 ( V_2 , V_43 , V_17 , V_4 + 1 ) ;
else
V_25 = F_34 ( V_2 , V_43 , V_17 ) ;
V_31:
F_14 ( V_14 ) ;
return V_25 ;
}
static inline T_6 F_36 ( struct V_1 * V_2 ,
struct V_43 * V_43 )
{
return F_35 ( V_2 , V_43 , V_54 , 0 ) ;
}
int F_37 ( struct V_1 * V_2 , struct V_43 * V_43 )
{
int type = V_43 -> V_46 . type ;
struct V_18 * V_19 = V_43 -> V_45 ;
T_6 V_61 ;
char * V_44 ;
int V_25 = 0 ;
#ifdef F_24
if ( ! F_38 ( V_43 -> V_45 ) -> V_62 [ type ] ) {
F_10 ( V_19 , L_29 ) ;
return - V_27 ;
}
#endif
if ( ! V_43 -> V_47 ) {
V_61 = F_36 ( V_2 , V_43 ) ;
if ( V_61 <= 0 ) {
if ( V_61 < 0 )
F_10 ( V_19 , L_30
L_31 ,
F_3 ( & V_10 ,
V_43 -> V_46 ) ) ;
V_43 -> V_47 = 0 ;
F_39 ( V_63 , & V_43 -> V_64 ) ;
memset ( & V_43 -> V_65 , 0 , sizeof( struct V_66 ) ) ;
V_25 = V_61 ;
goto V_67;
}
V_43 -> V_47 = V_61 ;
}
V_44 = F_5 ( V_2 -> V_12 ) ;
if ( ! V_44 )
return - V_29 ;
V_25 = V_19 -> V_21 -> V_22 ( V_19 , type , V_44 , V_2 -> V_12 ,
V_43 -> V_47 ) ;
if ( V_25 != V_2 -> V_12 ) {
if ( V_25 >= 0 )
V_25 = - V_27 ;
F_10 ( V_19 , L_32 ,
F_3 ( & V_10 , V_43 -> V_46 ) ) ;
F_39 ( V_63 , & V_43 -> V_64 ) ;
memset ( & V_43 -> V_65 , 0 , sizeof( struct V_66 ) ) ;
F_14 ( V_44 ) ;
goto V_67;
}
F_28 ( & V_43 -> V_55 ) ;
V_2 -> V_56 -> V_68 ( V_43 , V_44 ) ;
if ( ! V_43 -> V_65 . V_69 &&
! V_43 -> V_65 . V_70 &&
! V_43 -> V_65 . V_71 &&
! V_43 -> V_65 . V_72 )
F_39 ( V_63 , & V_43 -> V_64 ) ;
F_29 ( & V_43 -> V_55 ) ;
F_14 ( V_44 ) ;
V_67:
F_30 ( V_73 ) ;
return V_25 ;
}
int F_40 ( struct V_1 * V_2 , struct V_43 * V_43 )
{
if ( F_41 ( V_63 , & V_43 -> V_64 ) &&
! ( V_43 -> V_65 . V_74 | V_43 -> V_65 . V_75 ) )
return F_33 ( V_2 , V_43 ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 , T_1 * V_3 ,
unsigned int V_17 , int V_4 )
{
char * V_14 = F_5 ( V_2 -> V_6 ) ;
T_5 * V_51 = ( T_5 * ) V_14 ;
T_3 V_25 ;
unsigned int V_5 = V_2 -> V_6 >> 2 ;
unsigned int V_76 = 1 ;
int V_42 ;
if ( ! V_14 )
return - V_29 ;
for ( V_42 = V_4 ; V_42 < V_2 -> V_7 - 1 ; V_42 ++ )
V_76 *= V_5 ;
V_25 = F_8 ( V_2 , V_17 , V_14 ) ;
if ( V_25 < 0 ) {
F_10 ( V_2 -> V_20 ,
L_28 , V_17 ) ;
goto V_31;
}
for ( V_42 = F_1 ( V_2 , * V_3 , V_4 ) ; V_42 < V_5 ; V_42 ++ ) {
if ( V_51 [ V_42 ] == F_16 ( 0 ) ) {
* V_3 += V_76 ;
continue;
}
if ( V_4 == V_2 -> V_7 - 1 ) {
V_25 = 0 ;
goto V_31;
}
V_25 = F_42 ( V_2 , V_3 , F_12 ( V_51 [ V_42 ] ) , V_4 + 1 ) ;
if ( V_25 != - V_77 )
break;
}
if ( V_42 == V_5 ) {
V_25 = - V_77 ;
goto V_31;
}
V_31:
F_14 ( V_14 ) ;
return V_25 ;
}
int F_43 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
T_1 V_3 = F_3 ( & V_10 , * V_9 ) ;
int V_25 ;
V_25 = F_42 ( V_2 , & V_3 , V_54 , 0 ) ;
if ( V_25 < 0 )
return V_25 ;
* V_9 = F_44 ( & V_10 , V_9 -> type , V_3 ) ;
return 0 ;
}
