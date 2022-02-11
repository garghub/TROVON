int F_1 ( unsigned long V_1 , unsigned int V_2 ,
unsigned int V_3 , struct V_4 * V_5 )
{
struct V_6 * V_7 = V_8 -> V_7 ;
struct V_9 * V_10 ;
int V_11 = 0 ;
int V_12 ;
int V_13 ;
if ( V_2 == 0 )
return 0 ;
if ( F_2 ( V_2 > V_5 -> V_14 ) )
V_2 = V_5 -> V_14 ;
F_3 ( & V_7 -> V_15 ) ;
V_13 = 1 ;
V_10 = F_4 ( V_7 , V_1 , V_1 + 1 ) ;
if ( ! V_10 ) {
V_11 = - V_16 ;
goto V_17;
}
if ( ! ( V_10 -> V_18 & ( V_19 | V_20 ) ) ) {
V_5 -> V_21 = true ;
V_5 -> V_22 = false ;
V_11 = F_5 ( V_1 , V_2 ,
V_3 , (struct V_23 * * ) ( V_5 -> V_24 ) , & V_13 ) ;
goto V_17;
}
V_5 -> V_21 = false ;
V_5 -> V_22 = true ;
do {
unsigned long * V_25 = F_6 ( V_5 ) ;
while ( V_11 < V_2 && V_1 + V_26 <= V_10 -> V_27 ) {
V_12 = F_7 ( V_10 , V_1 , & V_25 [ V_11 ] ) ;
if ( V_12 ) {
if ( V_11 == 0 )
V_11 = V_12 ;
goto V_17;
}
V_1 += V_26 ;
V_11 ++ ;
}
if ( V_11 >= V_2 || V_1 < V_10 -> V_27 )
break;
V_10 = F_4 ( V_7 , V_1 , V_1 + 1 ) ;
} while ( V_10 && V_10 -> V_18 & ( V_19 | V_20 ) );
V_17:
if ( V_13 )
F_8 ( & V_7 -> V_15 ) ;
if ( ! V_11 )
V_11 = - V_16 ;
if ( V_11 > 0 )
V_5 -> V_2 = V_11 ;
return V_11 ;
}
void F_9 ( struct V_4 * V_5 )
{
int V_28 ;
struct V_23 * * V_29 ;
if ( ! V_5 -> V_21 )
goto V_17;
V_29 = F_10 ( V_5 ) ;
if ( F_11 ( F_12 ( V_29 ) ) )
goto V_17;
for ( V_28 = 0 ; V_28 < V_5 -> V_2 ; V_28 ++ )
F_13 ( V_29 [ V_28 ] ) ;
V_5 -> V_21 = false ;
V_17:
V_5 -> V_2 = 0 ;
}
int F_14 ( struct V_4 * V_5 )
{
int V_28 ;
unsigned long * V_25 ;
struct V_23 * * V_29 ;
if ( ! V_5 -> V_22 )
return 0 ;
V_25 = F_6 ( V_5 ) ;
for ( V_28 = 0 ; V_28 < V_5 -> V_2 ; V_28 ++ )
if ( ! F_15 ( V_25 [ V_28 ] ) )
return - V_30 ;
V_29 = (struct V_23 * * ) V_25 ;
for ( V_28 = 0 ; V_28 < V_5 -> V_2 ; V_28 ++ )
V_29 [ V_28 ] = F_16 ( V_25 [ V_28 ] ) ;
V_5 -> V_22 = false ;
return 0 ;
}
void F_17 ( struct V_4 * V_5 )
{
int V_28 ;
unsigned long * V_25 ;
struct V_23 * * V_29 ;
if ( V_5 -> V_22 )
return;
V_29 = (struct V_23 * * ) ( V_5 -> V_24 ) ;
V_25 = ( unsigned long * ) V_29 ;
for ( V_28 = 0 ; V_28 < V_5 -> V_2 ; V_28 ++ )
V_25 [ V_28 ] = F_18 ( V_29 [ V_28 ] ) ;
V_5 -> V_22 = true ;
}
struct V_4 * F_19 ( unsigned int V_2 )
{
struct V_4 * V_5 ;
int V_31 = sizeof( struct V_4 ) + sizeof( void * ) * V_2 ;
if ( F_2 ( V_2 == 0 ) )
return NULL ;
if ( F_2 ( V_2 > V_32 / sizeof( void * ) / 2 ) )
return NULL ;
V_5 = F_20 ( V_31 , V_33 ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_14 = V_2 ;
V_5 -> V_2 = 0 ;
return V_5 ;
}
void F_21 ( struct V_4 * V_5 )
{
F_22 ( V_5 -> V_2 > 0 ) ;
F_23 ( V_5 ) ;
}
