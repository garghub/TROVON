static int F_1 ( struct V_1 * V_2 )
{
return
( ( F_2 ( ( unsigned long ) V_2 -> V_3 + V_2 -> V_4 ) -
( ( unsigned long ) V_2 -> V_3 & V_5 ) ) >> V_6 ) ;
}
struct V_7 * F_3 ( struct V_1 * V_2 , T_1 V_8 )
{
struct V_7 * V_9 ;
struct V_10 * * V_11 ;
int V_12 ;
int V_13 ;
int V_14 = 0 ;
int V_15 = 0 ;
int V_16 = 0 ;
if ( F_4 ( F_5 () , V_17 ) )
return NULL ;
do {
V_15 += V_2 [ V_14 ] . V_4 ;
V_16 += F_1 ( & V_2 [ V_14 ] ) ;
V_14 ++ ;
} while ( V_15 < V_8 );
V_9 = F_6 ( sizeof( * V_9 )
+ ( V_14 * sizeof ( struct V_18 ) )
+ ( V_16 * sizeof ( struct V_10 * ) ) , V_19 ) ;
if ( ! V_9 )
goto V_20;
V_11 = (struct V_10 * * ) & V_9 -> V_21 [ V_14 ] ;
V_9 -> V_14 = 0 ;
for ( V_12 = 0 ; V_12 < V_14 ; V_12 ++ ) {
struct V_18 * V_21 = & V_9 -> V_21 [ V_12 ] ;
V_8 -= V_2 [ V_12 ] . V_4 ;
if ( ! F_7 ( V_22 , V_2 [ V_12 ] . V_3 , V_2 [ V_12 ] . V_4 ) )
goto V_23;
V_21 -> V_24 = F_1 ( & V_2 [ V_12 ] ) ;
V_21 -> V_25 = V_2 [ V_12 ] . V_3 ;
V_21 -> V_11 = V_11 ;
V_11 += V_21 -> V_24 ;
F_8 ( & V_26 -> V_27 -> V_28 ) ;
V_13 = F_9 (
V_26 ,
V_26 -> V_27 ,
( unsigned long ) V_2 [ V_12 ] . V_3 ,
V_21 -> V_24 ,
1 ,
0 ,
V_21 -> V_11 ,
NULL ) ;
F_10 ( & V_26 -> V_27 -> V_28 ) ;
if ( V_13 != V_21 -> V_24 )
goto V_23;
V_9 -> V_14 = V_12 + 1 ;
}
return V_9 ;
V_23:
F_11 ( V_9 ) ;
V_20:
return NULL ;
}
void F_11 ( struct V_7 * V_29 )
{
int V_12 , V_30 ;
if ( ! V_29 )
return;
for ( V_12 = 0 ; V_12 < V_29 -> V_14 ; V_12 ++ ) {
struct V_18 * V_21 = & V_29 -> V_21 [ V_12 ] ;
for ( V_30 = 0 ; V_30 < V_21 -> V_24 ; V_30 ++ ) {
F_12 ( V_21 -> V_11 [ V_30 ] ) ;
F_13 ( V_21 -> V_11 [ V_30 ] ) ;
}
}
F_14 ( V_29 ) ;
}
T_2 F_15 ( struct V_31 * V_32 , struct V_1 * V_2 ,
struct V_7 * V_29 , unsigned char * V_33 , T_1 V_8 )
{
int V_34 ;
int V_35 ;
T_2 V_36 = 0 ;
int V_37 ;
int V_38 ;
if ( ! V_32 )
return F_16 ( V_2 , V_33 , V_8 ) ;
V_37 = 0 ;
while ( V_37 < V_29 -> V_14 ) {
struct V_18 * V_21 ;
while ( ! V_2 [ V_37 ] . V_4 )
V_37 ++ ;
V_21 = & V_29 -> V_21 [ V_37 ] ;
V_34 = ( ( unsigned long ) V_2 [ V_37 ] . V_3 & ~ V_5 ) ;
V_38 = ( ( ( unsigned long ) V_2 [ V_37 ] . V_3 & V_5 )
- ( ( unsigned long ) V_21 -> V_25 & V_5 ) ) >> V_6 ;
while ( V_2 [ V_37 ] . V_4 ) {
V_35 = F_17 ( int , V_39 - V_34 , V_8 ) ;
V_35 = F_17 ( int , V_35 , V_2 [ V_37 ] . V_4 ) ;
V_36 = F_18 ( V_32 ,
V_21 -> V_11 [ V_38 ] ,
V_34 ,
V_33 ,
V_35 ) ;
if ( F_19 ( V_36 < 0 ) ) {
F_20 ( V_32 ) ;
continue;
}
V_8 -= V_35 ;
V_2 [ V_37 ] . V_4 -= V_35 ;
V_2 [ V_37 ] . V_3 += V_35 ;
if ( ! V_8 )
return V_36 ;
V_33 += V_35 ;
V_34 = 0 ;
V_38 ++ ;
}
V_37 ++ ;
}
F_21 () ;
return - V_40 ;
}
T_2 F_22 ( struct V_31 * V_32 , struct V_1 * V_2 ,
struct V_7 * V_29 , struct V_10 * V_10 ,
unsigned int V_41 , T_1 V_8 )
{
int V_34 ;
int V_35 ;
T_2 V_36 = 0 ;
int V_37 ;
int V_38 ;
int V_42 ;
if ( ! V_32 || ! V_29 ) {
T_3 * V_43 = F_23 ( V_10 ) ;
V_42 = F_16 ( V_2 , V_43 + V_41 , V_8 ) ;
F_24 ( V_10 ) ;
return V_42 ;
}
V_37 = 0 ;
while ( V_37 < V_29 -> V_14 ) {
struct V_18 * V_21 ;
while ( ! V_2 [ V_37 ] . V_4 )
V_37 ++ ;
V_21 = & V_29 -> V_21 [ V_37 ] ;
V_34 = ( ( unsigned long ) V_2 [ V_37 ] . V_3 & ~ V_5 ) ;
V_38 = ( ( ( unsigned long ) V_2 [ V_37 ] . V_3 & V_5 )
- ( ( unsigned long ) V_21 -> V_25 & V_5 ) ) >> V_6 ;
while ( V_2 [ V_37 ] . V_4 ) {
V_35 = F_17 ( int , V_39 - V_34 , V_8 ) ;
V_35 = F_17 ( int , V_35 , V_2 [ V_37 ] . V_4 ) ;
V_36 = F_25 ( V_32 ,
V_21 -> V_11 [ V_38 ] ,
V_34 ,
V_10 ,
V_41 ,
V_35 ) ;
if ( F_19 ( V_36 < 0 ) ) {
F_20 ( V_32 ) ;
continue;
}
V_8 -= V_35 ;
V_2 [ V_37 ] . V_4 -= V_35 ;
V_2 [ V_37 ] . V_3 += V_35 ;
if ( ! V_8 )
return V_36 ;
V_41 += V_35 ;
V_34 = 0 ;
V_38 ++ ;
}
V_37 ++ ;
}
F_21 () ;
return - V_40 ;
}
