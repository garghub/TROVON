static inline void F_1 ( struct V_1 * V_2 )
{
T_1 * V_3 = V_2 -> V_4 ;
V_2 -> V_5 -> V_6 = V_2 -> V_6 ;
V_2 -> V_6 -> V_5 = V_2 -> V_5 ;
if ( V_3 -> V_7 == V_2 ) {
V_3 -> V_7 = V_2 -> V_5 ;
if ( V_3 -> V_7 == V_2 )
V_3 -> V_7 = NULL ;
}
}
static inline void F_2 ( struct V_1 * V_2 )
{
T_1 * V_3 = V_2 -> V_4 ;
F_1 ( V_2 ) ;
if ( V_3 -> V_8 == V_2 ) {
V_3 -> V_8 = V_2 -> V_5 ;
if ( V_3 -> V_8 == V_2 )
V_3 -> V_8 = NULL ;
}
}
static inline void F_3 ( struct V_1 * V_2 )
{
T_1 * V_3 = V_2 -> V_4 ;
F_1 ( V_2 ) ;
if ( ! V_3 -> V_8 ) {
V_2 -> V_5 = V_2 -> V_6 = V_2 ;
} else {
V_2 -> V_5 = V_3 -> V_8 ;
V_2 -> V_6 = V_3 -> V_8 -> V_6 ;
V_2 -> V_6 -> V_5 = V_2 ;
V_2 -> V_5 -> V_6 = V_2 ;
}
V_3 -> V_8 = V_2 ;
}
static int F_4 ( struct V_1 * V_2 )
{
int V_9 = 0 ;
struct V_10 * V_11 = F_5 ( V_2 ) ;
if ( V_2 -> V_12 == V_13 && ! F_6 ( V_11 ) &&
! F_7 ( V_11 ) && ! F_8 ( V_11 ) ) {
F_9 ( V_2 , L_1 ) ;
V_9 = F_10 ( V_2 ) + 1 ;
F_11 ( V_11 ) ;
F_12 ( V_11 ) ;
F_13 ( V_11 , L_2 ) ;
F_14 ( V_11 ) ;
} else {
F_11 ( V_11 ) ;
}
return V_9 ;
}
void F_15 ( T_2 * V_14 )
{
int V_15 , V_16 ;
F_16 ( & V_14 -> V_17 ) ;
V_15 = F_17 ( V_14 ) ;
while ( F_18 ( V_14 ) < V_15 ) {
if ( V_14 -> V_18 & V_19 )
return;
F_19 ( & V_14 -> V_17 ) ;
F_20 ( & V_14 -> V_20 ) ;
F_21 ( & V_14 -> V_17 ) ;
F_21 ( & V_14 -> V_21 ) ;
V_15 = F_17 ( V_14 ) ;
V_16 = F_18 ( V_14 ) ;
if ( V_16 < V_15 ) {
int V_22 = V_14 -> V_23 != NULL ;
T_3 V_24 = 0 ;
if ( V_14 -> V_25 )
V_24 = V_14 -> V_25 -> V_26 ;
F_19 ( & V_14 -> V_21 ) ;
F_19 ( & V_14 -> V_17 ) ;
if ( V_22 ) {
F_22 ( V_14 ) ;
} else if ( F_23 ( V_14 ) == 0 ) {
;
} else if ( V_24 ) {
F_24 ( V_14 , V_24 ) ;
} else {
F_25 ( V_27 L_3
L_4 ,
V_28 , V_15 , V_16 ) ;
F_25 ( V_27 L_5
L_6 , V_28 ) ;
F_26 ( 1 ) ;
F_27 ( V_14 , 0 ) ;
}
F_21 ( & V_14 -> V_17 ) ;
} else {
F_19 ( & V_14 -> V_21 ) ;
}
F_28 ( & V_14 -> V_20 ) ;
}
}
static void F_29 ( T_2 * V_14 , struct V_10 * V_11 )
__releases( V_14 -> V_21 )
{
F_30 ( V_11 ) ;
F_19 ( & V_14 -> V_21 ) ;
F_31 ( V_11 ) ;
F_11 ( V_11 ) ;
F_32 ( V_11 ) ;
}
static int F_33 ( T_2 * V_14 , T_1 * V_3 )
{
struct V_1 * V_2 ;
struct V_10 * V_11 ;
T_3 V_29 ;
int V_30 = 0 ;
int V_9 = 0 ;
V_29 = V_3 -> V_26 ;
V_31:
if ( V_14 -> V_23 != V_3 ||
V_3 -> V_26 != V_29 )
return V_9 ;
while ( ! V_30 && V_3 -> V_8 ) {
V_2 = V_3 -> V_8 ;
V_11 = F_5 ( V_2 ) ;
if ( ! F_34 ( V_11 ) ) {
F_29 ( V_14 , V_11 ) ;
F_21 ( & V_14 -> V_21 ) ;
goto V_31;
}
if ( F_6 ( V_11 ) ) {
F_30 ( V_11 ) ;
F_19 ( & V_14 -> V_21 ) ;
F_11 ( V_11 ) ;
F_35 ( V_11 ) ;
F_13 ( V_11 , L_7 ) ;
F_14 ( V_11 ) ;
F_21 ( & V_14 -> V_21 ) ;
goto V_31;
}
if ( F_36 ( F_8 ( V_11 ) ) )
V_9 = - V_32 ;
V_30 = F_10 ( V_2 ) ;
F_11 ( V_11 ) ;
F_12 ( V_11 ) ;
F_14 ( V_11 ) ;
}
return V_9 ;
}
static void
F_37 ( T_2 * V_14 , struct V_10 * * V_33 , int * V_34 )
{
int V_35 ;
for ( V_35 = 0 ; V_35 < * V_34 ; V_35 ++ )
F_38 ( V_33 [ V_35 ] , V_36 ) ;
for ( V_35 = 0 ; V_35 < * V_34 ; V_35 ++ ) {
struct V_10 * V_11 = V_33 [ V_35 ] ;
F_39 ( V_11 ) ;
F_13 ( V_11 , L_7 ) ;
F_14 ( V_11 ) ;
}
* V_34 = 0 ;
}
static int F_40 ( T_2 * V_14 , struct V_1 * V_2 ,
struct V_10 * * V_33 , int * V_34 )
{
struct V_10 * V_11 = F_5 ( V_2 ) ;
int V_9 = 0 ;
if ( F_6 ( V_11 ) ) {
F_30 ( V_11 ) ;
F_19 ( & V_14 -> V_21 ) ;
F_11 ( V_11 ) ;
F_35 ( V_11 ) ;
F_13 ( V_11 , L_7 ) ;
F_14 ( V_11 ) ;
V_9 = 1 ;
} else if ( V_2 -> V_37 != NULL ) {
T_1 * V_38 = V_2 -> V_37 ;
T_3 V_24 = V_38 -> V_26 ;
F_19 ( & V_14 -> V_21 ) ;
F_11 ( V_11 ) ;
F_41 ( V_14 , V_24 ) ;
F_24 ( V_14 , V_24 ) ;
V_9 = 1 ;
} else if ( ! F_7 ( V_11 ) ) {
V_9 = 1 ;
if ( F_36 ( F_8 ( V_11 ) ) )
V_9 = - V_32 ;
F_42 ( V_2 , ! F_43 ( V_11 ) ) ;
F_13 ( V_11 , L_8 ) ;
F_10 ( V_2 ) ;
F_19 ( & V_14 -> V_21 ) ;
F_11 ( V_11 ) ;
F_12 ( V_11 ) ;
F_14 ( V_11 ) ;
} else {
F_13 ( V_11 , L_9 ) ;
F_30 ( V_11 ) ;
F_44 ( V_11 , ! F_45 ( V_11 ) ) ;
F_46 ( V_11 ) ;
V_33 [ * V_34 ] = V_11 ;
F_3 ( V_2 ) ;
F_11 ( V_11 ) ;
( * V_34 ) ++ ;
if ( * V_34 == V_39 ) {
F_19 ( & V_14 -> V_21 ) ;
F_37 ( V_14 , V_33 , V_34 ) ;
V_9 = 1 ;
}
}
return V_9 ;
}
int F_22 ( T_2 * V_14 )
{
T_1 * V_3 ;
T_3 V_29 ;
int V_40 ;
F_47 ( 1 , L_10 ) ;
V_40 = F_23 ( V_14 ) ;
F_47 ( 1 , L_11 , V_40 ) ;
if ( V_40 <= 0 )
return V_40 ;
V_40 = 0 ;
F_21 ( & V_14 -> V_21 ) ;
if ( ! V_14 -> V_23 )
goto V_41;
V_3 = V_14 -> V_23 ;
V_29 = V_3 -> V_26 ;
V_31:
if ( V_14 -> V_23 == V_3 &&
V_3 -> V_26 == V_29 ) {
int V_34 = 0 ;
struct V_10 * V_33 [ V_39 ] ;
struct V_1 * V_2 ;
int V_42 = 0 , V_43 ;
while ( ! V_42 && V_3 -> V_7 ) {
struct V_10 * V_11 ;
V_2 = V_3 -> V_7 ;
V_11 = F_5 ( V_2 ) ;
if ( ! F_34 ( V_11 ) ) {
F_29 ( V_14 , V_11 ) ;
V_42 = 1 ;
break;
}
V_42 = F_40 ( V_14 , V_2 , V_33 , & V_34 ) ;
if ( V_42 < 0 && ! V_40 )
V_40 = V_42 ;
if ( ! V_42 && ( F_48 () ||
F_49 ( & V_14 -> V_21 ) ) ) {
F_19 ( & V_14 -> V_21 ) ;
V_42 = 1 ;
break;
}
}
if ( V_34 ) {
if ( ! V_42 ) {
F_19 ( & V_14 -> V_21 ) ;
V_42 = 1 ;
}
F_37 ( V_14 , V_33 , & V_34 ) ;
}
if ( V_42 ) {
F_21 ( & V_14 -> V_21 ) ;
goto V_31;
}
V_43 = F_33 ( V_14 , V_3 ) ;
if ( ! V_40 )
V_40 = V_43 ;
}
V_41:
F_19 ( & V_14 -> V_21 ) ;
if ( V_40 < 0 )
F_27 ( V_14 , V_40 ) ;
else
V_40 = F_23 ( V_14 ) ;
return ( V_40 < 0 ) ? V_40 : 0 ;
}
int F_23 ( T_2 * V_14 )
{
T_1 * V_3 ;
T_3 V_44 ;
unsigned int V_45 , V_46 ;
if ( F_50 ( V_14 ) )
return 1 ;
F_21 ( & V_14 -> V_17 ) ;
F_21 ( & V_14 -> V_21 ) ;
V_3 = V_14 -> V_23 ;
if ( V_3 ) {
V_44 = V_3 -> V_26 ;
V_45 = V_3 -> V_47 ;
} else if ( ( V_3 = V_14 -> V_25 ) != NULL ) {
V_44 = V_3 -> V_26 ;
V_45 = V_3 -> V_47 ;
} else if ( ( V_3 = V_14 -> V_48 ) != NULL ) {
V_44 = V_3 -> V_26 ;
V_45 = V_14 -> V_49 ;
} else {
V_44 = V_14 -> V_50 ;
V_45 = V_14 -> V_49 ;
}
F_19 ( & V_14 -> V_21 ) ;
F_51 ( V_45 != 0 ) ;
if ( V_14 -> V_51 == V_44 ) {
F_19 ( & V_14 -> V_17 ) ;
return 1 ;
}
V_46 = V_45 - V_14 -> V_52 ;
if ( V_45 < V_14 -> V_52 )
V_46 = V_46 + V_14 -> V_53 - V_14 -> V_54 ;
F_47 ( 1 ,
L_12
L_13 ,
V_14 -> V_51 , V_44 , V_45 , V_46 ) ;
V_14 -> V_55 += V_46 ;
V_14 -> V_51 = V_44 ;
V_14 -> V_52 = V_45 ;
F_19 ( & V_14 -> V_17 ) ;
if ( ! ( V_14 -> V_18 & V_19 ) )
F_52 ( V_14 , 1 ) ;
return 0 ;
}
static int F_53 ( struct V_1 * V_2 , int * V_30 )
{
struct V_1 * V_56 ;
struct V_1 * V_57 = V_2 ;
int V_9 , V_46 = 0 ;
* V_30 = 0 ;
if ( ! V_2 )
return 0 ;
V_56 = V_2 -> V_6 ;
do {
V_2 = V_57 ;
V_57 = V_2 -> V_5 ;
if ( F_34 ( F_5 ( V_2 ) ) ) {
V_9 = F_4 ( V_2 ) ;
if ( V_9 ) {
V_46 ++ ;
if ( V_9 == 2 ) {
* V_30 = 1 ;
return V_46 ;
}
}
}
if ( F_48 () )
return V_46 ;
} while ( V_2 != V_56 );
return V_46 ;
}
int F_54 ( T_2 * V_14 )
{
T_1 * V_3 , * V_58 , * V_59 ;
int V_9 = 0 ;
int V_30 ;
V_3 = V_14 -> V_23 ;
if ( ! V_3 )
goto V_41;
V_58 = V_3 -> V_60 ;
V_59 = V_3 ;
do {
V_3 = V_59 ;
V_59 = V_3 -> V_61 ;
V_9 += F_53 ( V_3 ->
V_7 , & V_30 ) ;
if ( F_48 () )
goto V_41;
if ( V_30 )
continue;
V_9 += F_53 ( V_3 ->
V_8 , & V_30 ) ;
if ( F_48 () )
goto V_41;
} while ( V_3 != V_58 );
V_41:
return V_9 ;
}
int F_10 ( struct V_1 * V_2 )
{
T_1 * V_3 ;
T_2 * V_14 ;
int V_9 = 0 ;
F_9 ( V_2 , L_14 ) ;
if ( ( V_3 = V_2 -> V_4 ) == NULL ) {
F_9 ( V_2 , L_15 ) ;
goto V_41;
}
V_14 = V_3 -> V_62 ;
F_2 ( V_2 ) ;
V_2 -> V_4 = NULL ;
if ( V_3 -> V_7 != NULL ||
V_3 -> V_8 != NULL )
goto V_41;
F_9 ( V_2 , L_16 ) ;
if ( V_3 -> V_63 != V_64 ) {
F_9 ( V_2 , L_17 ) ;
goto V_41;
}
F_55 ( V_14 , V_3 ) ;
F_56 ( & V_14 -> V_65 ) ;
V_9 = 1 ;
V_41:
F_9 ( V_2 , L_18 ) ;
return V_9 ;
}
void F_57 ( struct V_1 * V_2 ,
T_1 * V_3 )
{
F_9 ( V_2 , L_14 ) ;
F_42 ( V_2 , F_7 ( F_5 ( V_2 ) ) || F_43 ( F_5 ( V_2 ) ) ) ;
F_42 ( V_2 , V_2 -> V_4 == NULL ) ;
V_2 -> V_4 = V_3 ;
if ( ! V_3 -> V_7 ) {
V_2 -> V_5 = V_2 -> V_6 = V_2 ;
} else {
V_2 -> V_5 = V_3 -> V_7 ;
V_2 -> V_6 = V_3 -> V_7 -> V_6 ;
V_2 -> V_6 -> V_5 = V_2 ;
V_2 -> V_5 -> V_6 = V_2 ;
}
V_3 -> V_7 = V_2 ;
}
void F_55 ( T_2 * V_14 , T_1 * V_3 )
{
F_16 ( & V_14 -> V_21 ) ;
if ( V_3 -> V_61 ) {
V_3 -> V_61 -> V_60 = V_3 -> V_60 ;
V_3 -> V_60 -> V_61 = V_3 -> V_61 ;
if ( V_14 -> V_23 == V_3 )
V_14 -> V_23 =
V_3 -> V_61 ;
if ( V_14 -> V_23 == V_3 )
V_14 -> V_23 = NULL ;
}
F_51 ( V_3 -> V_63 == V_64 ) ;
F_51 ( V_3 -> V_66 == NULL ) ;
F_51 ( V_3 -> V_67 == NULL ) ;
F_51 ( V_3 -> V_68 == NULL ) ;
F_51 ( V_3 -> V_69 == NULL ) ;
F_51 ( V_3 -> V_70 == NULL ) ;
F_51 ( V_3 -> V_71 == NULL ) ;
F_51 ( V_3 -> V_7 == NULL ) ;
F_51 ( V_3 -> V_8 == NULL ) ;
F_51 ( V_3 -> V_72 == 0 ) ;
F_51 ( V_14 -> V_25 != V_3 ) ;
F_51 ( V_14 -> V_48 != V_3 ) ;
F_47 ( 1 , L_19 , V_3 -> V_26 ) ;
F_58 ( V_3 ) ;
}
