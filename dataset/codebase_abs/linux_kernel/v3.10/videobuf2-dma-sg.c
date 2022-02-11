static void * F_1 ( void * V_1 , unsigned long V_2 , T_1 V_3 )
{
struct V_4 * V_5 ;
int V_6 ;
V_5 = F_2 ( sizeof *V_5 , V_7 ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_8 = NULL ;
V_5 -> V_9 = 0 ;
V_5 -> V_10 = 0 ;
V_5 -> V_11 . V_2 = V_2 ;
V_5 -> V_11 . V_12 = V_2 >> V_13 ;
V_5 -> V_11 . V_14 = F_3 ( V_5 -> V_11 . V_12 *
sizeof( * V_5 -> V_11 . V_14 ) ) ;
if ( ! V_5 -> V_11 . V_14 )
goto V_15;
F_4 ( V_5 -> V_11 . V_14 , V_5 -> V_11 . V_12 ) ;
V_5 -> V_16 = F_2 ( V_5 -> V_11 . V_12 * sizeof( struct V_17 * ) ,
V_7 ) ;
if ( ! V_5 -> V_16 )
goto V_18;
for ( V_6 = 0 ; V_6 < V_5 -> V_11 . V_12 ; ++ V_6 ) {
V_5 -> V_16 [ V_6 ] = F_5 ( V_7 | V_19 |
V_20 | V_3 ) ;
if ( NULL == V_5 -> V_16 [ V_6 ] )
goto V_21;
F_6 ( & V_5 -> V_11 . V_14 [ V_6 ] ,
V_5 -> V_16 [ V_6 ] , V_22 , 0 ) ;
}
V_5 -> V_23 . V_24 = & V_5 -> V_24 ;
V_5 -> V_23 . V_25 = V_26 ;
V_5 -> V_23 . V_27 = V_5 ;
F_7 ( & V_5 -> V_24 ) ;
F_8 ( 1 , L_1 ,
V_28 , V_5 -> V_11 . V_12 ) ;
return V_5 ;
V_21:
while ( -- V_6 >= 0 )
F_9 ( V_5 -> V_16 [ V_6 ] ) ;
F_10 ( V_5 -> V_16 ) ;
V_18:
F_11 ( V_5 -> V_11 . V_14 ) ;
V_15:
F_10 ( V_5 ) ;
return NULL ;
}
static void V_26 ( void * V_29 )
{
struct V_4 * V_5 = V_29 ;
int V_6 = V_5 -> V_11 . V_12 ;
if ( F_12 ( & V_5 -> V_24 ) ) {
F_8 ( 1 , L_2 , V_28 ,
V_5 -> V_11 . V_12 ) ;
if ( V_5 -> V_8 )
F_13 ( V_5 -> V_8 , V_5 -> V_11 . V_12 ) ;
F_11 ( V_5 -> V_11 . V_14 ) ;
while ( -- V_6 >= 0 )
F_9 ( V_5 -> V_16 [ V_6 ] ) ;
F_10 ( V_5 -> V_16 ) ;
F_10 ( V_5 ) ;
}
}
static void * F_14 ( void * V_1 , unsigned long V_8 ,
unsigned long V_2 , int V_9 )
{
struct V_4 * V_5 ;
unsigned long V_30 , V_31 ;
int V_32 , V_6 ;
V_5 = F_2 ( sizeof *V_5 , V_7 ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_8 = NULL ;
V_5 -> V_9 = V_9 ;
V_5 -> V_10 = V_8 & ~ V_33 ;
V_5 -> V_11 . V_2 = V_2 ;
V_30 = ( V_8 & V_33 ) >> V_13 ;
V_31 = ( ( V_8 + V_2 - 1 ) & V_33 ) >> V_13 ;
V_5 -> V_11 . V_12 = V_31 - V_30 + 1 ;
V_5 -> V_11 . V_14 = F_3 (
V_5 -> V_11 . V_12 * sizeof( * V_5 -> V_11 . V_14 ) ) ;
if ( ! V_5 -> V_11 . V_14 )
goto V_34;
F_4 ( V_5 -> V_11 . V_14 , V_5 -> V_11 . V_12 ) ;
V_5 -> V_16 = F_2 ( V_5 -> V_11 . V_12 * sizeof( struct V_17 * ) ,
V_7 ) ;
if ( ! V_5 -> V_16 )
goto V_35;
V_32 = F_15 ( V_36 , V_36 -> V_37 ,
V_8 & V_33 ,
V_5 -> V_11 . V_12 ,
V_9 ,
1 ,
V_5 -> V_16 ,
NULL ) ;
if ( V_32 != V_5 -> V_11 . V_12 )
goto V_38;
F_6 ( & V_5 -> V_11 . V_14 [ 0 ] , V_5 -> V_16 [ 0 ] ,
V_22 - V_5 -> V_10 , V_5 -> V_10 ) ;
V_2 -= V_22 - V_5 -> V_10 ;
for ( V_6 = 1 ; V_6 < V_5 -> V_11 . V_12 ; ++ V_6 ) {
F_6 ( & V_5 -> V_11 . V_14 [ V_6 ] , V_5 -> V_16 [ V_6 ] ,
F_16 ( V_39 , V_22 , V_2 ) , 0 ) ;
V_2 -= F_16 ( V_39 , V_22 , V_2 ) ;
}
return V_5 ;
V_38:
F_8 ( 1 , L_3 ,
V_32 , V_5 -> V_11 . V_12 ) ;
while ( -- V_32 >= 0 )
F_17 ( V_5 -> V_16 [ V_32 ] ) ;
F_10 ( V_5 -> V_16 ) ;
V_35:
F_11 ( V_5 -> V_11 . V_14 ) ;
V_34:
F_10 ( V_5 ) ;
return NULL ;
}
static void F_18 ( void * V_29 )
{
struct V_4 * V_5 = V_29 ;
int V_6 = V_5 -> V_11 . V_12 ;
F_8 ( 1 , L_4 ,
V_28 , V_5 -> V_11 . V_12 ) ;
if ( V_5 -> V_8 )
F_13 ( V_5 -> V_8 , V_5 -> V_11 . V_12 ) ;
while ( -- V_6 >= 0 ) {
if ( V_5 -> V_9 )
F_19 ( V_5 -> V_16 [ V_6 ] ) ;
F_17 ( V_5 -> V_16 [ V_6 ] ) ;
}
F_11 ( V_5 -> V_11 . V_14 ) ;
F_10 ( V_5 -> V_16 ) ;
F_10 ( V_5 ) ;
}
static void * F_20 ( void * V_29 )
{
struct V_4 * V_5 = V_29 ;
F_21 ( ! V_5 ) ;
if ( ! V_5 -> V_8 )
V_5 -> V_8 = F_22 ( V_5 -> V_16 ,
V_5 -> V_11 . V_12 ,
- 1 ,
V_40 ) ;
return V_5 -> V_8 + V_5 -> V_10 ;
}
static unsigned int F_23 ( void * V_29 )
{
struct V_4 * V_5 = V_29 ;
return F_24 ( & V_5 -> V_24 ) ;
}
static int F_25 ( void * V_29 , struct V_41 * V_42 )
{
struct V_4 * V_5 = V_29 ;
unsigned long V_43 = V_42 -> V_44 ;
unsigned long V_45 = V_42 -> V_46 - V_42 -> V_44 ;
int V_6 = 0 ;
if ( ! V_5 ) {
F_26 ( V_47 L_5 ) ;
return - V_48 ;
}
do {
int V_49 ;
V_49 = F_27 ( V_42 , V_43 , V_5 -> V_16 [ V_6 ++ ] ) ;
if ( V_49 ) {
F_26 ( V_47 L_6 , V_49 ) ;
return V_49 ;
}
V_43 += V_22 ;
V_45 -= V_22 ;
} while ( V_45 > 0 );
V_42 -> V_50 = & V_5 -> V_23 ;
V_42 -> V_51 = & V_52 ;
V_42 -> V_51 -> V_53 ( V_42 ) ;
return 0 ;
}
static void * F_28 ( void * V_29 )
{
struct V_4 * V_5 = V_29 ;
return & V_5 -> V_11 ;
}
