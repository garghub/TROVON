static void F_1 ( struct V_1 V_2 [] )
{
unsigned long long V_3 , V_4 , V_5 ;
unsigned long V_6 = 0 , V_7 ;
int V_8 = 0 , type ;
V_5 = F_2 () ;
V_4 = F_3 () ;
V_3 = V_5 * V_4 ;
if ( ! V_5 )
V_5 = 1ULL << 17 ;
if ( sizeof( long ) == 4 ) {
V_5 = F_4 ( V_9 , V_5 ) ;
V_3 = V_3 ? F_4 ( V_9 , V_3 ) : V_9 ;
}
do {
V_7 = 0 ;
type = F_5 ( V_6 ) ;
do {
V_7 += V_5 ;
if ( V_3 && V_6 + V_7 >= V_3 )
break;
} while ( type == F_5 ( V_6 + V_7 ) );
if ( type == V_10 || type == V_11 ) {
V_2 [ V_8 ] . V_6 = V_6 ;
V_2 [ V_8 ] . V_7 = V_7 ;
V_2 [ V_8 ] . type = type ;
V_8 ++ ;
}
V_6 += V_7 ;
} while ( V_6 < V_3 && V_8 < V_12 );
}
void F_6 ( struct V_1 V_2 [] )
{
unsigned long V_13 , V_14 ;
memset ( V_2 , 0 , V_12 * sizeof( struct V_1 ) ) ;
V_13 = F_7 ( 0xf8 ) ;
F_8 ( V_14 , 0 , 0 ) ;
F_9 ( 0 , 28 ) ;
F_1 ( V_2 ) ;
F_10 ( V_14 , 0 , 0 ) ;
F_11 ( V_13 ) ;
}
static void F_12 ( struct V_1 V_2 [] , int V_15 , int V_16 )
{
int V_17 = V_12 - V_15 ;
memmove ( & V_2 [ V_15 ] , & V_2 [ V_16 ] , V_17 * sizeof( struct V_1 ) ) ;
}
static void F_13 ( struct V_1 * V_2 , unsigned long V_6 ,
unsigned long V_7 , int type )
{
V_2 -> type = type ;
V_2 -> V_6 = V_6 ;
V_2 -> V_7 = V_7 ;
}
void F_14 ( struct V_1 V_2 [] , unsigned long V_6 ,
unsigned long V_7 , int type )
{
unsigned long V_18 , V_19 , V_20 , V_21 , V_22 , V_23 ;
int V_8 , V_24 ;
for ( V_8 = 0 ; V_8 < V_12 ; V_8 ++ ) {
if ( V_2 [ V_8 ] . V_7 == 0 )
continue;
V_21 = V_2 [ V_8 ] . V_6 ;
V_23 = V_2 [ V_8 ] . V_7 ;
V_22 = V_21 + V_23 - 1 ;
V_24 = V_2 [ V_8 ] . type ;
if ( V_6 + V_7 <= V_21 )
continue;
if ( V_6 > V_22 )
continue;
V_18 = F_15 ( V_6 , V_2 [ V_8 ] . V_6 ) ;
V_19 = F_4 ( V_6 + V_7 - 1 , V_22 ) ;
V_20 = V_19 - V_18 + 1 ;
if ( V_18 == V_21 && V_19 == V_22 ) {
F_13 ( & V_2 [ V_8 ] , V_18 , V_20 , type ) ;
} else if ( V_19 == V_22 ) {
F_12 ( V_2 , V_8 + 1 , V_8 ) ;
F_13 ( & V_2 [ V_8 ] , V_21 , V_23 - V_20 ,
V_24 ) ;
F_13 ( & V_2 [ V_8 + 1 ] , V_18 , V_20 , type ) ;
V_8 += 1 ;
} else if ( V_18 == V_21 ) {
F_12 ( V_2 , V_8 + 1 , V_8 ) ;
F_13 ( & V_2 [ V_8 ] , V_18 , V_20 , type ) ;
F_13 ( & V_2 [ V_8 + 1 ] , V_19 + 1 ,
V_23 - V_20 , V_24 ) ;
break;
} else {
F_12 ( V_2 , V_8 + 2 , V_8 ) ;
F_13 ( & V_2 [ V_8 ] , V_21 ,
V_18 - V_21 , V_24 ) ;
F_13 ( & V_2 [ V_8 + 1 ] , V_18 , V_20 , type ) ;
F_13 ( & V_2 [ V_8 + 2 ] , V_19 + 1 ,
V_22 - V_19 , V_24 ) ;
break;
}
}
}
