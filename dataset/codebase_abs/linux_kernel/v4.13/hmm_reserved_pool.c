static unsigned int F_1 ( void * V_1 ,
struct V_2 * V_3 ,
unsigned int V_4 , bool V_5 )
{
unsigned long V_6 ;
unsigned int V_7 = 0 ;
unsigned int V_8 ;
int V_9 ;
struct V_10 * V_11 = V_1 ;
if ( ! V_11 )
return 0 ;
F_2 ( & V_11 -> V_12 , V_6 ) ;
if ( V_11 -> V_13 ) {
V_8 = V_11 -> V_14 ;
for ( V_9 = V_8 - 1 ; V_9 >= 0 ; V_9 -- ) {
V_3 [ V_7 ] . V_15 = V_11 -> V_16 [ V_9 ] ;
V_3 [ V_7 ] . type = V_17 ;
V_7 ++ ;
V_11 -> V_14 -- ;
if ( V_7 == V_4 )
break;
}
}
F_3 ( & V_11 -> V_12 , V_6 ) ;
return V_7 ;
}
static void F_4 ( void * V_1 ,
struct V_2 * V_3 )
{
unsigned long V_6 ;
struct V_10 * V_11 = V_1 ;
if ( ! V_11 )
return;
F_2 ( & V_11 -> V_12 , V_6 ) ;
if ( V_11 -> V_13 &&
V_11 -> V_14 < V_11 -> V_18 &&
V_3 -> type == V_17 ) {
V_11 -> V_16 [ V_11 -> V_14 ++ ] = V_3 -> V_15 ;
}
F_3 ( & V_11 -> V_12 , V_6 ) ;
}
static int F_5 ( struct V_10 * * V_11 ,
unsigned int V_19 )
{
struct V_10 * V_20 ;
V_20 = F_6 ( sizeof( struct V_10 ) ,
V_21 ) ;
if ( F_7 ( ! V_20 ) ) {
F_8 ( V_22 , L_1 ) ;
return - V_23 ;
}
V_20 -> V_16 = F_6 ( sizeof( struct V_15 * ) * V_19 ,
V_21 ) ;
if ( F_7 ( ! V_20 -> V_16 ) ) {
F_8 ( V_22 , L_2 ) ;
F_9 ( V_20 ) ;
return - V_23 ;
}
V_20 -> V_14 = 0 ;
V_20 -> V_18 = 0 ;
F_10 ( & V_20 -> V_12 ) ;
V_20 -> V_13 = true ;
* V_11 = V_20 ;
return 0 ;
}
static int F_11 ( void * * V_1 , unsigned int V_19 )
{
int V_24 ;
unsigned int V_25 ;
unsigned int V_18 = V_19 ;
unsigned int V_26 = 0 ;
unsigned int V_7 = 0 ;
int V_27 = 0 ;
struct V_15 * V_16 ;
int V_9 ;
struct V_10 * V_11 ;
if ( V_19 == 0 )
return 0 ;
V_24 = F_5 ( & V_11 , V_19 ) ;
if ( V_24 ) {
F_8 ( V_22 , L_3 ) ;
return V_24 ;
}
V_18 = V_19 ;
V_7 = 0 ;
V_26 = V_28 ;
while ( V_18 ) {
V_25 = 1U << V_26 ;
while ( V_25 > V_18 ) {
V_26 -- ;
V_25 >>= 1U ;
}
F_12 ( V_26 > V_28 ) ;
V_16 = F_13 ( V_21 | V_29 , V_26 ) ;
if ( F_7 ( ! V_16 ) ) {
if ( V_26 == 0 ) {
V_27 ++ ;
F_8 ( V_22 , L_4 ,
V_30 , V_27 ) ;
if ( V_27 == V_31 )
goto V_32;
} else {
V_26 -- ;
}
} else {
V_25 = 1U << V_26 ;
V_24 = F_14 ( V_16 , V_25 ) ;
if ( V_24 ) {
F_8 ( V_22 ,
L_5 ) ;
F_15 ( V_16 , V_26 ) ;
goto V_32;
}
for ( V_9 = 0 ; V_9 < V_25 ; V_9 ++ )
V_11 -> V_16 [ V_7 ++ ] = V_16 + V_9 ;
V_11 -> V_14 += V_25 ;
V_11 -> V_18 += V_25 ;
V_18 -= V_25 ;
V_27 = 0 ;
}
}
V_32:
V_11 -> V_13 = true ;
* V_1 = V_11 ;
F_16 ( V_22 ,
L_6
L_7 ,
V_11 -> V_18 ) ;
return 0 ;
}
static void F_17 ( void * * V_1 )
{
unsigned long V_6 ;
int V_7 , V_24 ;
unsigned int V_18 ;
struct V_10 * V_11 = * V_1 ;
if ( ! V_11 )
return;
F_2 ( & V_11 -> V_12 , V_6 ) ;
if ( ! V_11 -> V_13 ) {
F_3 ( & V_11 -> V_12 , V_6 ) ;
return;
}
V_18 = V_11 -> V_18 ;
V_11 -> V_14 = 0 ;
V_11 -> V_18 = 0 ;
V_11 -> V_13 = false ;
F_3 ( & V_11 -> V_12 , V_6 ) ;
for ( V_7 = 0 ; V_7 < V_18 ; V_7 ++ ) {
V_24 = F_18 ( V_11 -> V_16 [ V_7 ] , 1 ) ;
if ( V_24 )
F_8 ( V_22 ,
L_8 , V_24 ) ;
if ( ! V_24 )
F_15 ( V_11 -> V_16 [ V_7 ] , 0 ) ;
}
F_9 ( V_11 -> V_16 ) ;
F_9 ( V_11 ) ;
* V_1 = NULL ;
}
static int F_19 ( void * V_1 )
{
struct V_10 * V_11 = V_1 ;
if ( ! V_11 )
return 0 ;
return V_11 -> V_13 ;
}
