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
V_2 -> V_17 , 0 , V_5 , V_3 ) ;
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
static void * F_15 ( void * V_15 , unsigned long V_18 ,
unsigned long V_5 , int V_19 )
{
struct V_1 * V_2 ;
unsigned long V_33 , V_34 ;
int V_35 ;
V_2 = F_7 ( sizeof *V_2 , V_11 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_18 = NULL ;
V_2 -> V_19 = V_19 ;
V_2 -> V_20 = V_18 & ~ V_36 ;
V_2 -> V_5 = V_5 ;
V_33 = ( V_18 & V_36 ) >> V_21 ;
V_34 = ( ( V_18 + V_5 - 1 ) & V_36 ) >> V_21 ;
V_2 -> V_17 = V_34 - V_33 + 1 ;
V_2 -> V_7 = F_7 ( V_2 -> V_17 * sizeof( struct V_6 * ) ,
V_11 ) ;
if ( ! V_2 -> V_7 )
goto V_37;
V_35 = F_16 ( V_38 , V_38 -> V_39 ,
V_18 & V_36 ,
V_2 -> V_17 ,
V_19 ,
1 ,
V_2 -> V_7 ,
NULL ) ;
if ( V_35 != V_2 -> V_17 )
goto V_40;
if ( F_8 ( & V_2 -> V_24 , V_2 -> V_7 ,
V_2 -> V_17 , V_2 -> V_20 , V_5 , 0 ) )
goto V_41;
return V_2 ;
V_41:
V_40:
F_10 ( 1 , L_3 ,
V_35 , V_2 -> V_17 ) ;
while ( -- V_35 >= 0 )
F_17 ( V_2 -> V_7 [ V_35 ] ) ;
F_11 ( V_2 -> V_7 ) ;
V_37:
F_11 ( V_2 ) ;
return NULL ;
}
static void F_18 ( void * V_32 )
{
struct V_1 * V_2 = V_32 ;
int V_9 = V_2 -> V_17 ;
F_10 ( 1 , L_4 ,
V_31 , V_2 -> V_17 ) ;
if ( V_2 -> V_18 )
F_13 ( V_2 -> V_18 , V_2 -> V_17 ) ;
F_14 ( & V_2 -> V_24 ) ;
while ( -- V_9 >= 0 ) {
if ( V_2 -> V_19 )
F_19 ( V_2 -> V_7 [ V_9 ] ) ;
F_17 ( V_2 -> V_7 [ V_9 ] ) ;
}
F_11 ( V_2 -> V_7 ) ;
F_11 ( V_2 ) ;
}
static void * F_20 ( void * V_32 )
{
struct V_1 * V_2 = V_32 ;
F_21 ( ! V_2 ) ;
if ( ! V_2 -> V_18 )
V_2 -> V_18 = F_22 ( V_2 -> V_7 ,
V_2 -> V_17 ,
- 1 ,
V_42 ) ;
return V_2 -> V_18 + V_2 -> V_20 ;
}
static unsigned int F_23 ( void * V_32 )
{
struct V_1 * V_2 = V_32 ;
return F_24 ( & V_2 -> V_27 ) ;
}
static int F_25 ( void * V_32 , struct V_43 * V_44 )
{
struct V_1 * V_2 = V_32 ;
unsigned long V_45 = V_44 -> V_46 ;
unsigned long V_47 = V_44 -> V_48 - V_44 -> V_46 ;
int V_9 = 0 ;
if ( ! V_2 ) {
F_26 ( V_49 L_5 ) ;
return - V_50 ;
}
do {
int V_16 ;
V_16 = F_27 ( V_44 , V_45 , V_2 -> V_7 [ V_9 ++ ] ) ;
if ( V_16 ) {
F_26 ( V_49 L_6 , V_16 ) ;
return V_16 ;
}
V_45 += V_10 ;
V_47 -= V_10 ;
} while ( V_47 > 0 );
V_44 -> V_51 = & V_2 -> V_26 ;
V_44 -> V_52 = & V_53 ;
V_44 -> V_52 -> V_54 ( V_44 ) ;
return 0 ;
}
static void * F_28 ( void * V_32 )
{
struct V_1 * V_2 = V_32 ;
return & V_2 -> V_24 ;
}
