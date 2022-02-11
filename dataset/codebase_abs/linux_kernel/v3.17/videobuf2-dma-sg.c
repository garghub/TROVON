static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 )
{
unsigned int V_4 = 0 ;
int V_5 = V_2 -> V_5 ;
while ( V_5 > 0 ) {
struct V_6 * V_7 ;
int V_8 ;
int V_9 ;
V_8 = F_2 ( V_5 ) ;
if ( ( V_10 << V_8 ) > V_5 )
V_8 -- ;
V_7 = NULL ;
while ( ! V_7 ) {
V_7 = F_3 ( V_11 | V_12 |
V_13 | V_3 , V_8 ) ;
if ( V_7 )
break;
if ( V_8 == 0 ) {
while ( V_4 -- )
F_4 ( V_2 -> V_7 [ V_4 ] ) ;
return - V_14 ;
}
V_8 -- ;
}
F_5 ( V_7 , V_8 ) ;
for ( V_9 = 0 ; V_9 < ( 1 << V_8 ) ; V_9 ++ )
V_2 -> V_7 [ V_4 ++ ] = & V_7 [ V_9 ] ;
V_5 -= V_10 << V_8 ;
}
return 0 ;
}
static void * F_6 ( void * V_15 , unsigned long V_5 , T_1 V_3 )
{
struct V_1 * V_2 ;
int V_16 ;
int V_17 ;
V_2 = F_7 ( sizeof *V_2 , V_11 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_18 = NULL ;
V_2 -> V_19 = 0 ;
V_2 -> V_20 = 0 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_17 = V_5 >> V_21 ;
V_2 -> V_7 = F_7 ( V_2 -> V_17 * sizeof( struct V_6 * ) ,
V_11 ) ;
if ( ! V_2 -> V_7 )
goto V_22;
V_16 = F_1 ( V_2 , V_3 ) ;
if ( V_16 )
goto V_23;
V_16 = F_8 ( & V_2 -> V_24 , V_2 -> V_7 ,
V_2 -> V_17 , 0 , V_5 , V_11 ) ;
if ( V_16 )
goto V_25;
V_2 -> V_26 . V_27 = & V_2 -> V_27 ;
V_2 -> V_26 . V_28 = V_29 ;
V_2 -> V_26 . V_30 = V_2 ;
F_9 ( & V_2 -> V_27 ) ;
F_10 ( 1 , L_1 ,
V_31 , V_2 -> V_17 ) ;
return V_2 ;
V_25:
V_17 = V_2 -> V_17 ;
while ( V_17 -- )
F_4 ( V_2 -> V_7 [ V_17 ] ) ;
V_23:
F_11 ( V_2 -> V_7 ) ;
V_22:
F_11 ( V_2 ) ;
return NULL ;
}
static void V_29 ( void * V_32 )
{
struct V_1 * V_2 = V_32 ;
int V_9 = V_2 -> V_17 ;
if ( F_12 ( & V_2 -> V_27 ) ) {
F_10 ( 1 , L_2 , V_31 ,
V_2 -> V_17 ) ;
if ( V_2 -> V_18 )
F_13 ( V_2 -> V_18 , V_2 -> V_17 ) ;
F_14 ( & V_2 -> V_24 ) ;
while ( -- V_9 >= 0 )
F_4 ( V_2 -> V_7 [ V_9 ] ) ;
F_11 ( V_2 -> V_7 ) ;
F_11 ( V_2 ) ;
}
}
static inline int F_15 ( struct V_33 * V_34 )
{
return ! ! ( V_34 -> V_35 & ( V_36 | V_37 ) ) ;
}
static void * F_16 ( void * V_15 , unsigned long V_18 ,
unsigned long V_5 , int V_19 )
{
struct V_1 * V_2 ;
unsigned long V_38 , V_39 ;
int V_40 ;
struct V_33 * V_34 ;
V_2 = F_7 ( sizeof *V_2 , V_11 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_18 = NULL ;
V_2 -> V_19 = V_19 ;
V_2 -> V_20 = V_18 & ~ V_41 ;
V_2 -> V_5 = V_5 ;
V_38 = ( V_18 & V_41 ) >> V_21 ;
V_39 = ( ( V_18 + V_5 - 1 ) & V_41 ) >> V_21 ;
V_2 -> V_17 = V_39 - V_38 + 1 ;
V_2 -> V_7 = F_7 ( V_2 -> V_17 * sizeof( struct V_6 * ) ,
V_11 ) ;
if ( ! V_2 -> V_7 )
goto V_42;
V_34 = F_17 ( V_43 -> V_44 , V_18 ) ;
if ( ! V_34 ) {
F_10 ( 1 , L_3 , V_18 ) ;
goto V_45;
}
if ( V_34 -> V_46 < V_18 + V_5 ) {
F_10 ( 1 , L_4 ,
V_18 , V_5 ) ;
goto V_45;
}
V_2 -> V_34 = F_18 ( V_34 ) ;
if ( ! V_2 -> V_34 ) {
F_10 ( 1 , L_5 ) ;
goto V_45;
}
if ( F_15 ( V_2 -> V_34 ) ) {
for ( V_40 = 0 ;
V_40 < V_2 -> V_17 ;
++ V_40 , V_18 += V_10 ) {
unsigned long V_47 ;
if ( F_19 ( V_34 , V_18 , & V_47 ) ) {
F_10 ( 1 , L_6 , V_18 ) ;
break;
}
V_2 -> V_7 [ V_40 ] = F_20 ( V_47 ) ;
}
} else
V_40 = F_21 ( V_43 , V_43 -> V_44 ,
V_18 & V_41 ,
V_2 -> V_17 ,
V_19 ,
1 ,
V_2 -> V_7 ,
NULL ) ;
if ( V_40 != V_2 -> V_17 )
goto V_48;
if ( F_8 ( & V_2 -> V_24 , V_2 -> V_7 ,
V_2 -> V_17 , V_2 -> V_20 , V_5 , 0 ) )
goto V_49;
return V_2 ;
V_49:
V_48:
F_10 ( 1 , L_7 ,
V_2 -> V_17 , V_40 ) ;
if ( ! F_15 ( V_2 -> V_34 ) )
while ( -- V_40 >= 0 )
F_22 ( V_2 -> V_7 [ V_40 ] ) ;
F_23 ( V_2 -> V_34 ) ;
V_45:
F_11 ( V_2 -> V_7 ) ;
V_42:
F_11 ( V_2 ) ;
return NULL ;
}
static void F_24 ( void * V_32 )
{
struct V_1 * V_2 = V_32 ;
int V_9 = V_2 -> V_17 ;
F_10 ( 1 , L_8 ,
V_31 , V_2 -> V_17 ) ;
if ( V_2 -> V_18 )
F_13 ( V_2 -> V_18 , V_2 -> V_17 ) ;
F_14 ( & V_2 -> V_24 ) ;
while ( -- V_9 >= 0 ) {
if ( V_2 -> V_19 )
F_25 ( V_2 -> V_7 [ V_9 ] ) ;
if ( ! F_15 ( V_2 -> V_34 ) )
F_22 ( V_2 -> V_7 [ V_9 ] ) ;
}
F_11 ( V_2 -> V_7 ) ;
F_23 ( V_2 -> V_34 ) ;
F_11 ( V_2 ) ;
}
static void * F_26 ( void * V_32 )
{
struct V_1 * V_2 = V_32 ;
F_27 ( ! V_2 ) ;
if ( ! V_2 -> V_18 )
V_2 -> V_18 = F_28 ( V_2 -> V_7 ,
V_2 -> V_17 ,
- 1 ,
V_50 ) ;
return V_2 -> V_18 + V_2 -> V_20 ;
}
static unsigned int F_29 ( void * V_32 )
{
struct V_1 * V_2 = V_32 ;
return F_30 ( & V_2 -> V_27 ) ;
}
static int F_31 ( void * V_32 , struct V_33 * V_34 )
{
struct V_1 * V_2 = V_32 ;
unsigned long V_51 = V_34 -> V_52 ;
unsigned long V_53 = V_34 -> V_46 - V_34 -> V_52 ;
int V_9 = 0 ;
if ( ! V_2 ) {
F_32 ( V_54 L_9 ) ;
return - V_55 ;
}
do {
int V_16 ;
V_16 = F_33 ( V_34 , V_51 , V_2 -> V_7 [ V_9 ++ ] ) ;
if ( V_16 ) {
F_32 ( V_54 L_10 , V_16 ) ;
return V_16 ;
}
V_51 += V_10 ;
V_53 -= V_10 ;
} while ( V_53 > 0 );
V_34 -> V_56 = & V_2 -> V_26 ;
V_34 -> V_57 = & V_58 ;
V_34 -> V_57 -> V_59 ( V_34 ) ;
return 0 ;
}
static void * F_34 ( void * V_32 )
{
struct V_1 * V_2 = V_32 ;
return & V_2 -> V_24 ;
}
