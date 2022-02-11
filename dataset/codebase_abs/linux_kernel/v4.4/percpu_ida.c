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
V_10 ; V_10 -- ) {
V_11 = F_4 ( V_11 , & V_7 -> V_10 ) ;
if ( V_11 >= V_14 ) {
V_11 = F_5 ( & V_7 -> V_10 ) ;
if ( V_11 >= V_14 )
F_6 () ;
}
V_7 -> V_12 = V_11 ;
V_13 = F_7 ( V_7 -> V_15 , V_11 ) ;
F_8 ( V_11 , & V_7 -> V_10 ) ;
if ( V_13 == V_9 )
continue;
F_9 ( & V_13 -> V_16 ) ;
if ( V_13 -> V_17 ) {
memcpy ( V_9 -> V_18 ,
V_13 -> V_18 ,
sizeof( unsigned ) * V_13 -> V_17 ) ;
V_9 -> V_17 = V_13 -> V_17 ;
V_13 -> V_17 = 0 ;
}
F_10 ( & V_13 -> V_16 ) ;
if ( V_9 -> V_17 )
break;
}
}
static inline void F_11 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
F_1 ( V_9 -> V_18 , & V_9 -> V_17 ,
V_7 -> V_18 , & V_7 -> V_17 ,
F_12 ( V_7 -> V_17 , V_7 -> V_19 ) ) ;
}
static inline unsigned F_13 ( struct V_8 * V_9 )
{
int V_20 = - V_21 ;
F_9 ( & V_9 -> V_16 ) ;
if ( V_9 -> V_17 )
V_20 = V_9 -> V_18 [ -- V_9 -> V_17 ] ;
F_10 ( & V_9 -> V_16 ) ;
return V_20 ;
}
int F_14 ( struct V_6 * V_7 , int V_22 )
{
F_15 ( V_23 ) ;
struct V_8 * V_9 ;
unsigned long V_24 ;
int V_20 ;
F_16 ( V_24 ) ;
V_9 = F_17 ( V_7 -> V_15 ) ;
V_20 = F_13 ( V_9 ) ;
if ( F_18 ( V_20 >= 0 ) ) {
F_19 ( V_24 ) ;
return V_20 ;
}
while ( 1 ) {
F_9 ( & V_7 -> V_16 ) ;
if ( V_22 != V_25 )
F_20 ( & V_7 -> V_23 , & V_23 , V_22 ) ;
if ( ! V_9 -> V_17 )
F_11 ( V_7 , V_9 ) ;
if ( ! V_9 -> V_17 )
F_2 ( V_7 , V_9 ) ;
if ( V_9 -> V_17 ) {
V_20 = V_9 -> V_18 [ -- V_9 -> V_17 ] ;
if ( V_9 -> V_17 )
F_21 ( F_22 () ,
& V_7 -> V_10 ) ;
}
F_10 ( & V_7 -> V_16 ) ;
F_19 ( V_24 ) ;
if ( V_20 >= 0 || V_22 == V_25 )
break;
if ( F_23 ( V_22 , V_26 ) ) {
V_20 = - V_27 ;
break;
}
F_24 () ;
F_16 ( V_24 ) ;
V_9 = F_17 ( V_7 -> V_15 ) ;
}
if ( V_22 != V_25 )
F_25 ( & V_7 -> V_23 , & V_23 ) ;
return V_20 ;
}
void F_26 ( struct V_6 * V_7 , unsigned V_20 )
{
struct V_8 * V_9 ;
unsigned long V_24 ;
unsigned V_17 ;
F_27 ( V_20 >= V_7 -> V_28 ) ;
F_16 ( V_24 ) ;
V_9 = F_17 ( V_7 -> V_15 ) ;
F_9 ( & V_9 -> V_16 ) ;
V_9 -> V_18 [ V_9 -> V_17 ++ ] = V_20 ;
V_17 = V_9 -> V_17 ;
F_10 ( & V_9 -> V_16 ) ;
if ( V_17 == 1 ) {
F_21 ( F_22 () ,
& V_7 -> V_10 ) ;
F_28 ( & V_7 -> V_23 ) ;
}
if ( V_17 == V_7 -> V_29 ) {
F_9 ( & V_7 -> V_16 ) ;
if ( V_9 -> V_17 == V_7 -> V_29 ) {
F_1 ( V_7 -> V_18 , & V_7 -> V_17 ,
V_9 -> V_18 , & V_9 -> V_17 ,
V_7 -> V_19 ) ;
F_28 ( & V_7 -> V_23 ) ;
}
F_10 ( & V_7 -> V_16 ) ;
}
F_19 ( V_24 ) ;
}
void F_29 ( struct V_6 * V_7 )
{
F_30 ( V_7 -> V_15 ) ;
F_31 ( ( unsigned long ) V_7 -> V_18 ,
F_32 ( V_7 -> V_28 * sizeof( unsigned ) ) ) ;
}
int F_33 ( struct V_6 * V_7 , unsigned long V_28 ,
unsigned long V_30 , unsigned long V_31 )
{
unsigned V_32 , V_11 , V_33 ;
memset ( V_7 , 0 , sizeof( * V_7 ) ) ;
F_34 ( & V_7 -> V_23 ) ;
F_35 ( & V_7 -> V_16 ) ;
V_7 -> V_28 = V_28 ;
V_7 -> V_29 = V_30 ;
V_7 -> V_19 = V_31 ;
if ( V_28 > ( unsigned ) V_34 + 1 ) {
F_36 ( L_1 ) ;
return - V_35 ;
}
V_33 = F_32 ( V_28 * sizeof( unsigned ) ) ;
V_7 -> V_18 = ( void * ) F_37 ( V_36 , V_33 ) ;
if ( ! V_7 -> V_18 )
return - V_37 ;
for ( V_32 = 0 ; V_32 < V_28 ; V_32 ++ )
V_7 -> V_18 [ V_32 ] = V_32 ;
V_7 -> V_17 = V_28 ;
V_7 -> V_15 = F_38 ( sizeof( struct V_8 ) +
V_7 -> V_29 * sizeof( unsigned ) ,
sizeof( unsigned ) ) ;
if ( ! V_7 -> V_15 )
goto V_38;
F_39 (cpu)
F_35 ( & F_7 ( V_7 -> V_15 , V_11 ) -> V_16 ) ;
return 0 ;
V_38:
F_29 ( V_7 ) ;
return - V_37 ;
}
int F_40 ( struct V_6 * V_7 , T_1 V_39 ,
void * V_40 )
{
unsigned long V_24 ;
struct V_8 * V_13 ;
unsigned V_11 , V_32 , V_38 = 0 ;
F_16 ( V_24 ) ;
F_39 (cpu) {
V_13 = F_7 ( V_7 -> V_15 , V_11 ) ;
F_9 ( & V_13 -> V_16 ) ;
for ( V_32 = 0 ; V_32 < V_13 -> V_17 ; V_32 ++ ) {
V_38 = V_39 ( V_13 -> V_18 [ V_32 ] , V_40 ) ;
if ( V_38 )
break;
}
F_10 ( & V_13 -> V_16 ) ;
if ( V_38 )
goto V_41;
}
F_9 ( & V_7 -> V_16 ) ;
for ( V_32 = 0 ; V_32 < V_7 -> V_17 ; V_32 ++ ) {
V_38 = V_39 ( V_7 -> V_18 [ V_32 ] , V_40 ) ;
if ( V_38 )
break;
}
F_10 ( & V_7 -> V_16 ) ;
V_41:
F_19 ( V_24 ) ;
return V_38 ;
}
unsigned F_41 ( struct V_6 * V_7 , int V_11 )
{
struct V_8 * V_13 ;
if ( V_11 == V_14 )
return V_7 -> V_17 ;
V_13 = F_7 ( V_7 -> V_15 , V_11 ) ;
return V_13 -> V_17 ;
}
