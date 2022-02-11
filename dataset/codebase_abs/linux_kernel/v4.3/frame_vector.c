int F_1 ( unsigned long V_1 , unsigned int V_2 ,
bool V_3 , bool V_4 , struct V_5 * V_6 )
{
struct V_7 * V_8 = V_9 -> V_8 ;
struct V_10 * V_11 ;
int V_12 = 0 ;
int V_13 ;
int V_14 ;
if ( V_2 == 0 )
return 0 ;
if ( F_2 ( V_2 > V_6 -> V_15 ) )
V_2 = V_6 -> V_15 ;
F_3 ( & V_8 -> V_16 ) ;
V_14 = 1 ;
V_11 = F_4 ( V_8 , V_1 , V_1 + 1 ) ;
if ( ! V_11 ) {
V_12 = - V_17 ;
goto V_18;
}
if ( ! ( V_11 -> V_19 & ( V_20 | V_21 ) ) ) {
V_6 -> V_22 = true ;
V_6 -> V_23 = false ;
V_12 = F_5 ( V_9 , V_8 , V_1 , V_2 ,
V_3 , V_4 , (struct V_24 * * ) ( V_6 -> V_25 ) , & V_14 ) ;
goto V_18;
}
V_6 -> V_22 = false ;
V_6 -> V_23 = true ;
do {
unsigned long * V_26 = F_6 ( V_6 ) ;
while ( V_12 < V_2 && V_1 + V_27 <= V_11 -> V_28 ) {
V_13 = F_7 ( V_11 , V_1 , & V_26 [ V_12 ] ) ;
if ( V_13 ) {
if ( V_12 == 0 )
V_12 = V_13 ;
goto V_18;
}
V_1 += V_27 ;
V_12 ++ ;
}
if ( V_12 >= V_2 || V_1 < V_11 -> V_28 )
break;
V_11 = F_4 ( V_8 , V_1 , V_1 + 1 ) ;
} while ( V_11 && V_11 -> V_19 & ( V_20 | V_21 ) );
V_18:
if ( V_14 )
F_8 ( & V_8 -> V_16 ) ;
if ( ! V_12 )
V_12 = - V_17 ;
if ( V_12 > 0 )
V_6 -> V_2 = V_12 ;
return V_12 ;
}
void F_9 ( struct V_5 * V_6 )
{
int V_29 ;
struct V_24 * * V_30 ;
if ( ! V_6 -> V_22 )
goto V_18;
V_30 = F_10 ( V_6 ) ;
if ( F_11 ( F_12 ( V_30 ) ) )
goto V_18;
for ( V_29 = 0 ; V_29 < V_6 -> V_2 ; V_29 ++ )
F_13 ( V_30 [ V_29 ] ) ;
V_6 -> V_22 = false ;
V_18:
V_6 -> V_2 = 0 ;
}
int F_14 ( struct V_5 * V_6 )
{
int V_29 ;
unsigned long * V_26 ;
struct V_24 * * V_30 ;
if ( ! V_6 -> V_23 )
return 0 ;
V_26 = F_6 ( V_6 ) ;
for ( V_29 = 0 ; V_29 < V_6 -> V_2 ; V_29 ++ )
if ( ! F_15 ( V_26 [ V_29 ] ) )
return - V_31 ;
V_30 = (struct V_24 * * ) V_26 ;
for ( V_29 = 0 ; V_29 < V_6 -> V_2 ; V_29 ++ )
V_30 [ V_29 ] = F_16 ( V_26 [ V_29 ] ) ;
V_6 -> V_23 = false ;
return 0 ;
}
void F_17 ( struct V_5 * V_6 )
{
int V_29 ;
unsigned long * V_26 ;
struct V_24 * * V_30 ;
if ( V_6 -> V_23 )
return;
V_30 = (struct V_24 * * ) ( V_6 -> V_25 ) ;
V_26 = ( unsigned long * ) V_30 ;
for ( V_29 = 0 ; V_29 < V_6 -> V_2 ; V_29 ++ )
V_26 [ V_29 ] = F_18 ( V_30 [ V_29 ] ) ;
V_6 -> V_23 = true ;
}
struct V_5 * F_19 ( unsigned int V_2 )
{
struct V_5 * V_6 ;
int V_32 = sizeof( struct V_5 ) + sizeof( void * ) * V_2 ;
if ( F_2 ( V_2 == 0 ) )
return NULL ;
if ( F_2 ( V_2 > V_33 / sizeof( void * ) / 2 ) )
return NULL ;
if ( V_32 <= V_27 )
V_6 = F_20 ( V_32 , V_34 ) ;
else
V_6 = F_21 ( V_32 ) ;
if ( ! V_6 )
return NULL ;
V_6 -> V_15 = V_2 ;
V_6 -> V_2 = 0 ;
return V_6 ;
}
void F_22 ( struct V_5 * V_6 )
{
F_23 ( V_6 -> V_2 > 0 ) ;
F_24 ( V_6 ) ;
}
