static inline void F_1 ( unsigned * V_1 , unsigned * V_2 ,
unsigned * V_3 , unsigned * V_4 ,
unsigned V_5 )
{
* V_4 -= V_5 ;
memcpy ( V_1 + * V_2 , V_3 + * V_4 , sizeof( unsigned ) * V_5 ) ;
* V_2 += V_5 ;
}
static inline void F_2 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
unsigned V_10 , V_11 = V_7 -> V_12 ;
struct V_8 * V_13 ;
for ( V_10 = F_3 ( & V_7 -> V_10 ) ;
V_10 * V_14 > V_7 -> V_15 / 2 ;
V_10 -- ) {
V_11 = F_4 ( V_11 , & V_7 -> V_10 ) ;
if ( V_11 >= V_16 ) {
V_11 = F_5 ( & V_7 -> V_10 ) ;
if ( V_11 >= V_16 )
F_6 () ;
}
V_7 -> V_12 = V_11 ;
V_13 = F_7 ( V_7 -> V_17 , V_11 ) ;
F_8 ( V_11 , & V_7 -> V_10 ) ;
if ( V_13 == V_9 )
continue;
F_9 ( & V_13 -> V_18 ) ;
if ( V_13 -> V_19 ) {
memcpy ( V_9 -> V_20 ,
V_13 -> V_20 ,
sizeof( unsigned ) * V_13 -> V_19 ) ;
V_9 -> V_19 = V_13 -> V_19 ;
V_13 -> V_19 = 0 ;
}
F_10 ( & V_13 -> V_18 ) ;
if ( V_9 -> V_19 )
break;
}
}
static inline void F_11 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
F_1 ( V_9 -> V_20 , & V_9 -> V_19 ,
V_7 -> V_20 , & V_7 -> V_19 ,
F_12 ( V_7 -> V_19 , V_21 ) ) ;
}
static inline unsigned F_13 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
int V_22 = - V_23 ;
F_9 ( & V_9 -> V_18 ) ;
if ( V_9 -> V_19 )
V_22 = V_9 -> V_20 [ -- V_9 -> V_19 ] ;
F_10 ( & V_9 -> V_18 ) ;
return V_22 ;
}
int F_14 ( struct V_6 * V_7 , T_1 V_24 )
{
F_15 ( V_25 ) ;
struct V_8 * V_9 ;
unsigned long V_26 ;
int V_22 ;
F_16 ( V_26 ) ;
V_9 = F_17 ( V_7 -> V_17 ) ;
V_22 = F_13 ( V_7 , V_9 ) ;
if ( F_18 ( V_22 >= 0 ) ) {
F_19 ( V_26 ) ;
return V_22 ;
}
while ( 1 ) {
F_9 ( & V_7 -> V_18 ) ;
F_20 ( & V_7 -> V_25 , & V_25 , V_27 ) ;
if ( ! V_9 -> V_19 )
F_11 ( V_7 , V_9 ) ;
if ( ! V_9 -> V_19 )
F_2 ( V_7 , V_9 ) ;
if ( V_9 -> V_19 ) {
V_22 = V_9 -> V_20 [ -- V_9 -> V_19 ] ;
if ( V_9 -> V_19 )
F_21 ( F_22 () ,
& V_7 -> V_10 ) ;
}
F_10 ( & V_7 -> V_18 ) ;
F_19 ( V_26 ) ;
if ( V_22 >= 0 || ! ( V_24 & V_28 ) )
break;
F_23 () ;
F_16 ( V_26 ) ;
V_9 = F_17 ( V_7 -> V_17 ) ;
}
F_24 ( & V_7 -> V_25 , & V_25 ) ;
return V_22 ;
}
void F_25 ( struct V_6 * V_7 , unsigned V_22 )
{
struct V_8 * V_9 ;
unsigned long V_26 ;
unsigned V_19 ;
F_26 ( V_22 >= V_7 -> V_15 ) ;
F_16 ( V_26 ) ;
V_9 = F_17 ( V_7 -> V_17 ) ;
F_9 ( & V_9 -> V_18 ) ;
V_9 -> V_20 [ V_9 -> V_19 ++ ] = V_22 ;
V_19 = V_9 -> V_19 ;
F_10 ( & V_9 -> V_18 ) ;
if ( V_19 == 1 ) {
F_21 ( F_22 () ,
& V_7 -> V_10 ) ;
F_27 ( & V_7 -> V_25 ) ;
}
if ( V_19 == V_14 ) {
F_9 ( & V_7 -> V_18 ) ;
if ( V_9 -> V_19 == V_14 ) {
F_1 ( V_7 -> V_20 , & V_7 -> V_19 ,
V_9 -> V_20 , & V_9 -> V_19 ,
V_21 ) ;
F_27 ( & V_7 -> V_25 ) ;
}
F_10 ( & V_7 -> V_18 ) ;
}
F_19 ( V_26 ) ;
}
void F_28 ( struct V_6 * V_7 )
{
F_29 ( V_7 -> V_17 ) ;
F_30 ( ( unsigned long ) V_7 -> V_20 ,
F_31 ( V_7 -> V_15 * sizeof( unsigned ) ) ) ;
}
int F_32 ( struct V_6 * V_7 , unsigned long V_15 )
{
unsigned V_29 , V_11 , V_30 ;
memset ( V_7 , 0 , sizeof( * V_7 ) ) ;
F_33 ( & V_7 -> V_25 ) ;
F_34 ( & V_7 -> V_18 ) ;
V_7 -> V_15 = V_15 ;
if ( V_15 > ( unsigned ) V_31 + 1 ) {
F_35 ( L_1 ) ;
return - V_32 ;
}
V_30 = F_31 ( V_15 * sizeof( unsigned ) ) ;
V_7 -> V_20 = ( void * ) F_36 ( V_33 , V_30 ) ;
if ( ! V_7 -> V_20 )
return - V_34 ;
for ( V_29 = 0 ; V_29 < V_15 ; V_29 ++ )
V_7 -> V_20 [ V_29 ] = V_29 ;
V_7 -> V_19 = V_15 ;
V_7 -> V_17 = F_37 ( sizeof( struct V_8 ) +
V_14 * sizeof( unsigned ) ,
sizeof( unsigned ) ) ;
if ( ! V_7 -> V_17 )
goto V_35;
F_38 (cpu)
F_34 ( & F_7 ( V_7 -> V_17 , V_11 ) -> V_18 ) ;
return 0 ;
V_35:
F_28 ( V_7 ) ;
return - V_34 ;
}
