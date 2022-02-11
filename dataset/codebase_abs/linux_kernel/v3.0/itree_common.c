static inline void F_1 ( T_1 * V_1 , struct V_2 * V_3 , T_2 * V_4 )
{
V_1 -> V_5 = * ( V_1 -> V_1 = V_4 ) ;
V_1 -> V_3 = V_3 ;
}
static inline int F_2 ( T_1 * V_6 , T_1 * V_7 )
{
while ( V_6 <= V_7 && V_6 -> V_5 == * V_6 -> V_1 )
V_6 ++ ;
return ( V_6 > V_7 ) ;
}
static inline T_2 * F_3 ( struct V_2 * V_3 )
{
return ( T_2 * ) ( ( char * ) V_3 -> V_8 + V_3 -> V_9 ) ;
}
static inline T_1 * F_4 ( struct V_10 * V_10 ,
int V_11 ,
int * V_12 ,
T_1 V_13 [ V_14 ] ,
int * V_15 )
{
struct V_16 * V_17 = V_10 -> V_18 ;
T_1 * V_1 = V_13 ;
struct V_2 * V_3 ;
* V_15 = 0 ;
F_1 ( V_13 , NULL , F_5 ( V_10 ) + * V_12 ) ;
if ( ! V_1 -> V_5 )
goto V_19;
while ( -- V_11 ) {
V_3 = F_6 ( V_17 , F_7 ( V_1 -> V_5 ) ) ;
if ( ! V_3 )
goto V_20;
F_8 ( & V_21 ) ;
if ( ! F_2 ( V_13 , V_1 ) )
goto V_22;
F_1 ( ++ V_1 , V_3 , ( T_2 * ) V_3 -> V_8 + * ++ V_12 ) ;
F_9 ( & V_21 ) ;
if ( ! V_1 -> V_5 )
goto V_19;
}
return NULL ;
V_22:
F_9 ( & V_21 ) ;
F_10 ( V_3 ) ;
* V_15 = - V_23 ;
goto V_19;
V_20:
* V_15 = - V_24 ;
V_19:
return V_1 ;
}
static int F_11 ( struct V_10 * V_10 ,
int V_25 ,
int * V_12 ,
T_1 * V_26 )
{
int V_27 = 0 ;
int V_28 ;
int V_29 = F_12 ( V_10 ) ;
V_26 [ 0 ] . V_5 = F_13 ( V_29 ) ;
if ( V_29 ) for ( V_27 = 1 ; V_27 < V_25 ; V_27 ++ ) {
struct V_2 * V_3 ;
int V_30 = F_12 ( V_10 ) ;
if ( ! V_30 )
break;
V_26 [ V_27 ] . V_5 = F_13 ( V_30 ) ;
V_3 = F_14 ( V_10 -> V_18 , V_29 ) ;
F_15 ( V_3 ) ;
memset ( V_3 -> V_8 , 0 , V_3 -> V_9 ) ;
V_26 [ V_27 ] . V_3 = V_3 ;
V_26 [ V_27 ] . V_1 = ( T_2 * ) V_3 -> V_8 + V_12 [ V_27 ] ;
* V_26 [ V_27 ] . V_1 = V_26 [ V_27 ] . V_5 ;
F_16 ( V_3 ) ;
F_17 ( V_3 ) ;
F_18 ( V_3 , V_10 ) ;
V_29 = V_30 ;
}
if ( V_27 == V_25 )
return 0 ;
for ( V_28 = 1 ; V_28 < V_27 ; V_28 ++ )
F_19 ( V_26 [ V_28 ] . V_3 ) ;
for ( V_28 = 0 ; V_28 < V_27 ; V_28 ++ )
F_20 ( V_10 , F_7 ( V_26 [ V_28 ] . V_5 ) ) ;
return - V_31 ;
}
static inline int F_21 ( struct V_10 * V_10 ,
T_1 V_13 [ V_14 ] ,
T_1 * V_32 ,
int V_25 )
{
int V_28 ;
F_22 ( & V_21 ) ;
if ( ! F_2 ( V_13 , V_32 - 1 ) || * V_32 -> V_1 )
goto V_22;
* V_32 -> V_1 = V_32 -> V_5 ;
F_23 ( & V_21 ) ;
V_10 -> V_33 = V_34 ;
if ( V_32 -> V_3 )
F_18 ( V_32 -> V_3 , V_10 ) ;
F_24 ( V_10 ) ;
return 0 ;
V_22:
F_23 ( & V_21 ) ;
for ( V_28 = 1 ; V_28 < V_25 ; V_28 ++ )
F_19 ( V_32 [ V_28 ] . V_3 ) ;
for ( V_28 = 0 ; V_28 < V_25 ; V_28 ++ )
F_20 ( V_10 , F_7 ( V_32 [ V_28 ] . V_5 ) ) ;
return - V_23 ;
}
static inline int F_25 ( struct V_10 * V_10 , T_3 V_35 ,
struct V_2 * V_3 , int V_36 )
{
int V_15 = - V_24 ;
int V_12 [ V_14 ] ;
T_1 V_13 [ V_14 ] ;
T_1 * V_37 ;
int V_38 ;
int V_11 = F_26 ( V_10 , V_35 , V_12 ) ;
if ( V_11 == 0 )
goto V_39;
V_40:
V_37 = F_4 ( V_10 , V_11 , V_12 , V_13 , & V_15 ) ;
if ( ! V_37 ) {
V_41:
F_27 ( V_3 , V_10 -> V_18 , F_7 ( V_13 [ V_11 - 1 ] . V_5 ) ) ;
V_37 = V_13 + V_11 - 1 ;
goto V_42;
}
if ( ! V_36 || V_15 == - V_24 ) {
V_42:
while ( V_37 > V_13 ) {
F_10 ( V_37 -> V_3 ) ;
V_37 -- ;
}
V_39:
return V_15 ;
}
if ( V_15 == - V_23 )
goto V_22;
V_38 = ( V_13 + V_11 ) - V_37 ;
V_15 = F_11 ( V_10 , V_38 , V_12 + ( V_37 - V_13 ) , V_37 ) ;
if ( V_15 )
goto V_42;
if ( F_21 ( V_10 , V_13 , V_37 , V_38 ) < 0 )
goto V_22;
F_28 ( V_3 ) ;
goto V_41;
V_22:
while ( V_37 > V_13 ) {
F_10 ( V_37 -> V_3 ) ;
V_37 -- ;
}
goto V_40;
}
static inline int F_29 ( T_2 * V_1 , T_2 * V_43 )
{
while ( V_1 < V_43 )
if ( * V_1 ++ )
return 0 ;
return 1 ;
}
static T_1 * F_30 ( struct V_10 * V_10 ,
int V_11 ,
int V_12 [ V_14 ] ,
T_1 V_13 [ V_14 ] ,
T_2 * V_44 )
{
T_1 * V_37 , * V_1 ;
int V_45 , V_15 ;
* V_44 = 0 ;
for ( V_45 = V_11 ; V_45 > 1 && ! V_12 [ V_45 - 1 ] ; V_45 -- )
;
V_37 = F_4 ( V_10 , V_45 , V_12 , V_13 , & V_15 ) ;
F_22 ( & V_21 ) ;
if ( ! V_37 )
V_37 = V_13 + V_45 - 1 ;
if ( ! V_37 -> V_5 && * V_37 -> V_1 ) {
F_23 ( & V_21 ) ;
goto V_46;
}
for ( V_1 = V_37 ; V_1 > V_13 && F_29 ( ( T_2 * ) V_1 -> V_3 -> V_8 , V_1 -> V_1 ) ; V_1 -- )
;
if ( V_1 == V_13 + V_45 - 1 && V_1 > V_13 ) {
V_1 -> V_1 -- ;
} else {
* V_44 = * V_1 -> V_1 ;
* V_1 -> V_1 = 0 ;
}
F_23 ( & V_21 ) ;
while( V_37 > V_1 )
{
F_10 ( V_37 -> V_3 ) ;
V_37 -- ;
}
V_46:
return V_37 ;
}
static inline void F_31 ( struct V_10 * V_10 , T_2 * V_1 , T_2 * V_43 )
{
unsigned long V_30 ;
for ( ; V_1 < V_43 ; V_1 ++ ) {
V_30 = F_7 ( * V_1 ) ;
if ( V_30 ) {
* V_1 = 0 ;
F_20 ( V_10 , V_30 ) ;
}
}
}
static void F_32 ( struct V_10 * V_10 , T_2 * V_1 , T_2 * V_43 , int V_11 )
{
struct V_2 * V_3 ;
unsigned long V_30 ;
if ( V_11 -- ) {
for ( ; V_1 < V_43 ; V_1 ++ ) {
V_30 = F_7 ( * V_1 ) ;
if ( ! V_30 )
continue;
* V_1 = 0 ;
V_3 = F_6 ( V_10 -> V_18 , V_30 ) ;
if ( ! V_3 )
continue;
F_32 ( V_10 , ( T_2 * ) V_3 -> V_8 ,
F_3 ( V_3 ) , V_11 ) ;
F_19 ( V_3 ) ;
F_20 ( V_10 , V_30 ) ;
F_24 ( V_10 ) ;
}
} else
F_31 ( V_10 , V_1 , V_43 ) ;
}
static inline void F_33 ( struct V_10 * V_10 )
{
struct V_16 * V_17 = V_10 -> V_18 ;
T_2 * V_47 = F_5 ( V_10 ) ;
int V_12 [ V_14 ] ;
T_1 V_13 [ V_14 ] ;
T_1 * V_37 ;
T_2 V_30 = 0 ;
int V_27 ;
int V_48 ;
long V_49 ;
V_49 = ( V_10 -> V_50 + V_17 -> V_51 - 1 ) >> V_17 -> V_52 ;
F_34 ( V_10 -> V_53 , V_10 -> V_50 , F_25 ) ;
V_27 = F_26 ( V_10 , V_49 , V_12 ) ;
if ( ! V_27 )
return;
if ( V_27 == 1 ) {
F_31 ( V_10 , V_47 + V_12 [ 0 ] , V_47 + V_54 ) ;
V_48 = 0 ;
goto V_55;
}
V_48 = V_12 [ 0 ] + 1 - V_54 ;
V_37 = F_30 ( V_10 , V_27 , V_12 , V_13 , & V_30 ) ;
if ( V_30 ) {
if ( V_37 == V_13 )
F_24 ( V_10 ) ;
else
F_18 ( V_37 -> V_3 , V_10 ) ;
F_32 ( V_10 , & V_30 , & V_30 + 1 , ( V_13 + V_27 - 1 ) - V_37 ) ;
}
while ( V_37 > V_13 ) {
F_32 ( V_10 , V_37 -> V_1 + 1 , F_3 ( V_37 -> V_3 ) ,
( V_13 + V_27 - 1 ) - V_37 ) ;
F_18 ( V_37 -> V_3 , V_10 ) ;
F_10 ( V_37 -> V_3 ) ;
V_37 -- ;
}
V_55:
while ( V_48 < V_14 - 1 ) {
V_30 = V_47 [ V_54 + V_48 ] ;
if ( V_30 ) {
V_47 [ V_54 + V_48 ] = 0 ;
F_24 ( V_10 ) ;
F_32 ( V_10 , & V_30 , & V_30 + 1 , V_48 + 1 ) ;
}
V_48 ++ ;
}
V_10 -> V_56 = V_10 -> V_33 = V_34 ;
F_24 ( V_10 ) ;
}
static inline unsigned F_35 ( T_4 V_57 , struct V_16 * V_17 )
{
int V_45 = V_17 -> V_52 - 10 ;
unsigned V_58 , V_59 , V_60 = V_54 , V_28 = V_14 ;
V_58 = ( V_57 + V_17 -> V_51 - 1 ) >> ( V_61 + V_45 ) ;
V_59 = V_58 ;
while ( -- V_28 && V_58 > V_60 ) {
V_58 -= V_60 ;
V_58 += V_17 -> V_51 / sizeof( T_2 ) - 1 ;
V_58 /= V_17 -> V_51 / sizeof( T_2 ) ;
V_59 += V_58 ;
V_60 = 1 ;
}
return V_59 ;
}
