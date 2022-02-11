static int F_1 ( struct V_1 * V_2 , T_1 V_3 , int V_4 )
{
unsigned int V_5 = V_2 -> V_6 >> 2 ;
V_4 = V_2 -> V_7 - V_4 - 1 ;
while ( V_4 -- )
V_3 /= V_5 ;
return V_3 % V_5 ;
}
static int F_2 ( struct V_1 * V_2 )
{
return ( V_2 -> V_6 - sizeof( struct V_8 ) )
/ V_2 -> V_9 ;
}
static char * F_3 ( T_2 V_10 )
{
char * V_11 = F_4 ( V_10 , V_12 ) ;
if ( ! V_11 )
F_5 ( V_13
L_1 ) ;
return V_11 ;
}
static T_3 F_6 ( struct V_1 * V_2 , T_4 V_14 , char * V_11 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
memset ( V_11 , 0 , V_2 -> V_6 ) ;
return V_16 -> V_18 -> V_19 ( V_16 , V_2 -> V_20 , V_11 ,
V_2 -> V_6 , V_14 << V_2 -> V_21 ) ;
}
static T_3 F_7 ( struct V_1 * V_2 , T_4 V_14 , char * V_11 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
T_3 V_22 ;
V_22 = V_16 -> V_18 -> V_23 ( V_16 , V_2 -> V_20 , V_11 ,
V_2 -> V_6 , V_14 << V_2 -> V_21 ) ;
if ( V_22 != V_2 -> V_6 ) {
F_8 ( V_16 , L_2 ) ;
if ( V_22 >= 0 )
V_22 = - V_24 ;
}
return V_22 ;
}
static int F_9 ( struct V_1 * V_2 )
{
char * V_11 = F_3 ( V_2 -> V_6 ) ;
struct V_8 * V_25 = (struct V_8 * ) V_11 ;
int V_22 , V_14 ;
if ( ! V_11 )
return - V_26 ;
if ( V_2 -> V_27 ) {
V_14 = V_2 -> V_27 ;
V_22 = F_6 ( V_2 , V_14 , V_11 ) ;
if ( V_22 < 0 )
goto V_28;
V_2 -> V_27 = F_10 ( V_25 -> V_29 ) ;
}
else {
memset ( V_11 , 0 , V_2 -> V_6 ) ;
V_22 = F_7 ( V_2 , V_2 -> V_30 , V_11 ) ;
if ( V_22 < 0 )
goto V_28;
V_14 = V_2 -> V_30 ++ ;
}
F_11 ( V_2 -> V_17 , V_2 -> V_20 ) ;
V_22 = V_14 ;
V_28:
F_12 ( V_11 ) ;
return V_22 ;
}
static int F_13 ( struct V_1 * V_2 , char * V_11 , T_4 V_14 )
{
struct V_8 * V_25 = (struct V_8 * ) V_11 ;
int V_31 ;
V_25 -> V_29 = F_14 ( V_2 -> V_27 ) ;
V_25 -> V_32 = F_14 ( 0 ) ;
V_25 -> V_33 = F_15 ( 0 ) ;
V_31 = F_7 ( V_2 , V_14 , V_11 ) ;
if ( V_31 < 0 )
return V_31 ;
V_2 -> V_27 = V_14 ;
F_11 ( V_2 -> V_17 , V_2 -> V_20 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , char * V_11 ,
T_4 V_14 )
{
char * V_34 = F_3 ( V_2 -> V_6 ) ;
struct V_8 * V_25 = (struct V_8 * ) V_11 ;
T_4 V_35 = F_10 ( V_25 -> V_29 ) ;
T_4 V_36 = F_10 ( V_25 -> V_32 ) ;
int V_31 ;
if ( ! V_34 )
return - V_26 ;
if ( V_35 ) {
V_31 = F_6 ( V_2 , V_35 , V_34 ) ;
if ( V_31 < 0 )
goto V_28;
( (struct V_8 * ) V_34 ) -> V_32 =
V_25 -> V_32 ;
V_31 = F_7 ( V_2 , V_35 , V_34 ) ;
if ( V_31 < 0 )
goto V_28;
}
if ( V_36 ) {
V_31 = F_6 ( V_2 , V_36 , V_34 ) ;
if ( V_31 < 0 )
goto V_28;
( (struct V_8 * ) V_34 ) -> V_29 =
V_25 -> V_29 ;
V_31 = F_7 ( V_2 , V_36 , V_34 ) ;
if ( V_31 < 0 )
goto V_28;
} else {
V_2 -> V_37 = V_35 ;
F_11 ( V_2 -> V_17 , V_2 -> V_20 ) ;
}
F_12 ( V_34 ) ;
V_25 -> V_29 = V_25 -> V_32 = F_14 ( 0 ) ;
if ( F_7 ( V_2 , V_14 , V_11 ) < 0 )
F_8 ( V_2 -> V_17 , L_3
L_4 , V_14 ) ;
return 0 ;
V_28:
F_12 ( V_34 ) ;
return V_31 ;
}
static int F_17 ( struct V_1 * V_2 , char * V_11 ,
T_4 V_14 )
{
char * V_34 = F_3 ( V_2 -> V_6 ) ;
struct V_8 * V_25 = (struct V_8 * ) V_11 ;
int V_31 ;
if ( ! V_34 )
return - V_26 ;
V_25 -> V_29 = F_14 ( V_2 -> V_37 ) ;
V_25 -> V_32 = F_14 ( 0 ) ;
V_31 = F_7 ( V_2 , V_14 , V_11 ) ;
if ( V_31 < 0 )
goto V_28;
if ( V_2 -> V_37 ) {
V_31 = F_6 ( V_2 , V_2 -> V_37 , V_34 ) ;
if ( V_31 < 0 )
goto V_28;
( (struct V_8 * ) V_34 ) -> V_32 =
F_14 ( V_14 ) ;
V_31 = F_7 ( V_2 , V_2 -> V_37 , V_34 ) ;
if ( V_31 < 0 )
goto V_28;
}
F_12 ( V_34 ) ;
V_2 -> V_37 = V_14 ;
F_11 ( V_2 -> V_17 , V_2 -> V_20 ) ;
return 0 ;
V_28:
F_12 ( V_34 ) ;
return V_31 ;
}
int F_18 ( struct V_1 * V_2 , char * V_38 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < V_2 -> V_9 ; V_39 ++ )
if ( V_38 [ V_39 ] )
return 0 ;
return 1 ;
}
static T_4 F_19 ( struct V_1 * V_2 ,
struct V_40 * V_40 , int * V_31 )
{
T_4 V_14 , V_39 ;
struct V_8 * V_25 ;
char * V_11 = F_3 ( V_2 -> V_6 ) ;
char * V_41 ;
* V_31 = 0 ;
if ( ! V_11 ) {
* V_31 = - V_26 ;
return 0 ;
}
V_25 = (struct V_8 * ) V_11 ;
if ( V_2 -> V_37 ) {
V_14 = V_2 -> V_37 ;
* V_31 = F_6 ( V_2 , V_14 , V_11 ) ;
if ( * V_31 < 0 )
goto V_28;
} else {
V_14 = F_9 ( V_2 ) ;
if ( ( int ) V_14 < 0 ) {
* V_31 = V_14 ;
F_12 ( V_11 ) ;
return 0 ;
}
memset ( V_11 , 0 , V_2 -> V_6 ) ;
V_2 -> V_37 = V_14 ;
F_11 ( V_40 -> V_42 , V_40 -> V_43 ) ;
}
if ( F_20 ( V_25 -> V_33 ) + 1 >= F_2 ( V_2 ) ) {
* V_31 = F_16 ( V_2 , V_11 , V_14 ) ;
if ( * V_31 < 0 ) {
F_8 ( V_40 -> V_42 , L_5
L_6 , V_14 ) ;
goto V_28;
}
}
F_21 ( & V_25 -> V_33 , 1 ) ;
V_41 = V_11 + sizeof( struct V_8 ) ;
for ( V_39 = 0 ; V_39 < F_2 ( V_2 ) ; V_39 ++ ) {
if ( F_18 ( V_2 , V_41 ) )
break;
V_41 += V_2 -> V_9 ;
}
#ifdef F_22
if ( V_39 == F_2 ( V_2 ) ) {
F_8 ( V_40 -> V_42 , L_7 ) ;
* V_31 = - V_24 ;
goto V_28;
}
#endif
* V_31 = F_7 ( V_2 , V_14 , V_11 ) ;
if ( * V_31 < 0 ) {
F_8 ( V_40 -> V_42 , L_8 ,
V_14 ) ;
goto V_28;
}
V_40 -> V_44 = ( V_14 << V_2 -> V_21 ) +
sizeof( struct V_8 ) +
V_39 * V_2 -> V_9 ;
F_12 ( V_11 ) ;
return V_14 ;
V_28:
F_12 ( V_11 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 , struct V_40 * V_40 ,
T_4 * V_45 , int V_4 )
{
char * V_11 = F_3 ( V_2 -> V_6 ) ;
int V_22 = 0 , V_46 = 0 , V_47 = 0 ;
T_5 * V_48 ;
T_4 V_49 ;
if ( ! V_11 )
return - V_26 ;
if ( ! * V_45 ) {
V_22 = F_9 ( V_2 ) ;
if ( V_22 < 0 )
goto V_28;
* V_45 = V_22 ;
memset ( V_11 , 0 , V_2 -> V_6 ) ;
V_47 = 1 ;
} else {
V_22 = F_6 ( V_2 , * V_45 , V_11 ) ;
if ( V_22 < 0 ) {
F_8 ( V_40 -> V_42 , L_9
L_10 , * V_45 ) ;
goto V_28;
}
}
V_48 = ( T_5 * ) V_11 ;
V_49 = F_10 ( V_48 [ F_1 ( V_2 , V_40 -> V_50 , V_4 ) ] ) ;
if ( ! V_49 )
V_46 = 1 ;
if ( V_4 == V_2 -> V_7 - 1 ) {
#ifdef F_22
if ( V_49 ) {
F_8 ( V_40 -> V_42 , L_11
L_12 ,
F_10 ( V_48 [ F_1 ( V_2 ,
V_40 -> V_50 , V_4 ) ] ) ) ;
V_22 = - V_24 ;
goto V_28;
}
#endif
V_49 = F_19 ( V_2 , V_40 , & V_22 ) ;
} else {
V_22 = F_23 ( V_2 , V_40 , & V_49 , V_4 + 1 ) ;
}
if ( V_46 && V_22 >= 0 ) {
V_48 [ F_1 ( V_2 , V_40 -> V_50 , V_4 ) ] =
F_14 ( V_49 ) ;
V_22 = F_7 ( V_2 , * V_45 , V_11 ) ;
} else if ( V_47 && V_22 < 0 ) {
F_13 ( V_2 , V_11 , * V_45 ) ;
}
V_28:
F_12 ( V_11 ) ;
return V_22 ;
}
static inline int F_24 ( struct V_1 * V_2 ,
struct V_40 * V_40 )
{
int V_51 = V_52 ;
return F_23 ( V_2 , V_40 , & V_51 , 0 ) ;
}
int F_25 ( struct V_1 * V_2 , struct V_40 * V_40 )
{
int type = V_40 -> V_43 ;
struct V_15 * V_16 = V_40 -> V_42 ;
T_3 V_22 ;
char * V_41 = F_3 ( V_2 -> V_9 ) ;
if ( ! V_41 )
return - V_26 ;
if ( ! V_40 -> V_44 ) {
V_22 = F_24 ( V_2 , V_40 ) ;
if ( V_22 < 0 ) {
F_8 ( V_16 , L_13
L_14 , V_22 ) ;
F_12 ( V_41 ) ;
return V_22 ;
}
}
F_26 ( & V_53 ) ;
V_2 -> V_54 -> V_55 ( V_41 , V_40 ) ;
F_27 ( & V_53 ) ;
V_22 = V_16 -> V_18 -> V_23 ( V_16 , type , V_41 , V_2 -> V_9 ,
V_40 -> V_44 ) ;
if ( V_22 != V_2 -> V_9 ) {
F_8 ( V_16 , L_2 ) ;
if ( V_22 >= 0 )
V_22 = - V_56 ;
} else {
V_22 = 0 ;
}
F_28 ( V_57 ) ;
F_12 ( V_41 ) ;
return V_22 ;
}
static int F_29 ( struct V_1 * V_2 , struct V_40 * V_40 ,
T_4 V_14 )
{
struct V_8 * V_25 ;
char * V_11 = F_3 ( V_2 -> V_6 ) ;
int V_22 = 0 ;
if ( ! V_11 )
return - V_26 ;
if ( V_40 -> V_44 >> V_2 -> V_21 != V_14 ) {
F_8 ( V_40 -> V_42 , L_15
L_16 , V_14 ,
( T_4 ) ( V_40 -> V_44 >> V_2 -> V_21 ) ) ;
goto V_28;
}
V_22 = F_6 ( V_2 , V_14 , V_11 ) ;
if ( V_22 < 0 ) {
F_8 ( V_40 -> V_42 , L_17 ,
V_14 ) ;
goto V_28;
}
V_25 = (struct V_8 * ) V_11 ;
F_21 ( & V_25 -> V_33 , - 1 ) ;
if ( ! F_20 ( V_25 -> V_33 ) ) {
V_22 = F_16 ( V_2 , V_11 , V_14 ) ;
if ( V_22 >= 0 )
V_22 = F_13 ( V_2 , V_11 , V_14 ) ;
if ( V_22 < 0 ) {
F_8 ( V_40 -> V_42 , L_18
L_19 , V_14 ) ;
goto V_28;
}
} else {
memset ( V_11 +
( V_40 -> V_44 & ( ( 1 << V_2 -> V_21 ) - 1 ) ) ,
0 , V_2 -> V_9 ) ;
if ( F_20 ( V_25 -> V_33 ) ==
F_2 ( V_2 ) - 1 ) {
V_22 = F_17 ( V_2 , V_11 , V_14 ) ;
if ( V_22 < 0 ) {
F_8 ( V_40 -> V_42 , L_20
L_21 , V_14 ) ;
goto V_28;
}
} else {
V_22 = F_7 ( V_2 , V_14 , V_11 ) ;
if ( V_22 < 0 ) {
F_8 ( V_40 -> V_42 , L_22
L_23 , V_14 ) ;
goto V_28;
}
}
}
V_40 -> V_44 = 0 ;
V_28:
F_12 ( V_11 ) ;
return V_22 ;
}
static int F_30 ( struct V_1 * V_2 , struct V_40 * V_40 ,
T_4 * V_14 , int V_4 )
{
char * V_11 = F_3 ( V_2 -> V_6 ) ;
int V_22 = 0 ;
T_4 V_49 ;
T_5 * V_48 = ( T_5 * ) V_11 ;
if ( ! V_11 )
return - V_26 ;
V_22 = F_6 ( V_2 , * V_14 , V_11 ) ;
if ( V_22 < 0 ) {
F_8 ( V_40 -> V_42 , L_17 ,
* V_14 ) ;
goto V_28;
}
V_49 = F_10 ( V_48 [ F_1 ( V_2 , V_40 -> V_50 , V_4 ) ] ) ;
if ( V_4 == V_2 -> V_7 - 1 ) {
V_22 = F_29 ( V_2 , V_40 , V_49 ) ;
V_49 = 0 ;
} else {
V_22 = F_30 ( V_2 , V_40 , & V_49 , V_4 + 1 ) ;
}
if ( V_22 >= 0 && ! V_49 ) {
int V_39 ;
V_48 [ F_1 ( V_2 , V_40 -> V_50 , V_4 ) ] = F_14 ( 0 ) ;
for ( V_39 = 0 ; V_39 < ( V_2 -> V_6 >> 2 ) && ! V_48 [ V_39 ] ; V_39 ++ )
;
if ( V_39 == ( V_2 -> V_6 >> 2 )
&& * V_14 != V_52 ) {
F_13 ( V_2 , V_11 , * V_14 ) ;
* V_14 = 0 ;
} else {
V_22 = F_7 ( V_2 , * V_14 , V_11 ) ;
if ( V_22 < 0 )
F_8 ( V_40 -> V_42 ,
L_24 ,
* V_14 ) ;
}
}
V_28:
F_12 ( V_11 ) ;
return V_22 ;
}
int F_31 ( struct V_1 * V_2 , struct V_40 * V_40 )
{
T_4 V_51 = V_52 ;
if ( ! V_40 -> V_44 )
return 0 ;
return F_30 ( V_2 , V_40 , & V_51 , 0 ) ;
}
static T_6 F_32 ( struct V_1 * V_2 ,
struct V_40 * V_40 , T_4 V_14 )
{
char * V_11 = F_3 ( V_2 -> V_6 ) ;
T_6 V_22 = 0 ;
int V_39 ;
char * V_41 ;
if ( ! V_11 )
return - V_26 ;
V_22 = F_6 ( V_2 , V_14 , V_11 ) ;
if ( V_22 < 0 ) {
F_8 ( V_40 -> V_42 , L_25
L_10 , V_14 ) ;
goto V_28;
}
V_41 = V_11 + sizeof( struct V_8 ) ;
for ( V_39 = 0 ; V_39 < F_2 ( V_2 ) ; V_39 ++ ) {
if ( V_2 -> V_54 -> V_58 ( V_41 , V_40 ) )
break;
V_41 += V_2 -> V_9 ;
}
if ( V_39 == F_2 ( V_2 ) ) {
F_8 ( V_40 -> V_42 , L_26
L_27 , V_40 -> V_50 ) ;
V_22 = - V_24 ;
goto V_28;
} else {
V_22 = ( V_14 << V_2 -> V_21 ) + sizeof( struct
V_8 ) + V_39 * V_2 -> V_9 ;
}
V_28:
F_12 ( V_11 ) ;
return V_22 ;
}
static T_6 F_33 ( struct V_1 * V_2 ,
struct V_40 * V_40 , T_4 V_14 , int V_4 )
{
char * V_11 = F_3 ( V_2 -> V_6 ) ;
T_6 V_22 = 0 ;
T_5 * V_48 = ( T_5 * ) V_11 ;
if ( ! V_11 )
return - V_26 ;
V_22 = F_6 ( V_2 , V_14 , V_11 ) ;
if ( V_22 < 0 ) {
F_8 ( V_40 -> V_42 , L_28 ,
V_14 ) ;
goto V_28;
}
V_22 = 0 ;
V_14 = F_10 ( V_48 [ F_1 ( V_2 , V_40 -> V_50 , V_4 ) ] ) ;
if ( ! V_14 )
goto V_28;
if ( V_4 < V_2 -> V_7 - 1 )
V_22 = F_33 ( V_2 , V_40 , V_14 , V_4 + 1 ) ;
else
V_22 = F_32 ( V_2 , V_40 , V_14 ) ;
V_28:
F_12 ( V_11 ) ;
return V_22 ;
}
static inline T_6 F_34 ( struct V_1 * V_2 ,
struct V_40 * V_40 )
{
return F_33 ( V_2 , V_40 , V_52 , 0 ) ;
}
int F_35 ( struct V_1 * V_2 , struct V_40 * V_40 )
{
int type = V_40 -> V_43 ;
struct V_15 * V_16 = V_40 -> V_42 ;
T_6 V_59 ;
char * V_41 ;
int V_22 = 0 ;
#ifdef F_22
if ( ! F_36 ( V_40 -> V_42 ) -> V_60 [ type ] ) {
F_8 ( V_16 , L_29 ) ;
return - V_24 ;
}
#endif
if ( ! V_40 -> V_44 ) {
V_59 = F_34 ( V_2 , V_40 ) ;
if ( V_59 <= 0 ) {
if ( V_59 < 0 )
F_8 ( V_16 , L_30
L_31 , V_40 -> V_50 ) ;
V_40 -> V_44 = 0 ;
F_37 ( V_61 , & V_40 -> V_62 ) ;
memset ( & V_40 -> V_63 , 0 , sizeof( struct V_64 ) ) ;
V_22 = V_59 ;
goto V_65;
}
V_40 -> V_44 = V_59 ;
}
V_41 = F_3 ( V_2 -> V_9 ) ;
if ( ! V_41 )
return - V_26 ;
V_22 = V_16 -> V_18 -> V_19 ( V_16 , type , V_41 , V_2 -> V_9 ,
V_40 -> V_44 ) ;
if ( V_22 != V_2 -> V_9 ) {
if ( V_22 >= 0 )
V_22 = - V_24 ;
F_8 ( V_16 , L_32 ,
V_40 -> V_50 ) ;
F_37 ( V_61 , & V_40 -> V_62 ) ;
memset ( & V_40 -> V_63 , 0 , sizeof( struct V_64 ) ) ;
F_12 ( V_41 ) ;
goto V_65;
}
F_26 ( & V_53 ) ;
V_2 -> V_54 -> V_66 ( V_40 , V_41 ) ;
if ( ! V_40 -> V_63 . V_67 &&
! V_40 -> V_63 . V_68 &&
! V_40 -> V_63 . V_69 &&
! V_40 -> V_63 . V_70 )
F_37 ( V_61 , & V_40 -> V_62 ) ;
F_27 ( & V_53 ) ;
F_12 ( V_41 ) ;
V_65:
F_28 ( V_71 ) ;
return V_22 ;
}
int F_38 ( struct V_1 * V_2 , struct V_40 * V_40 )
{
if ( F_39 ( V_61 , & V_40 -> V_62 ) &&
! ( V_40 -> V_63 . V_72 | V_40 -> V_63 . V_73 ) )
return F_31 ( V_2 , V_40 ) ;
return 0 ;
}
