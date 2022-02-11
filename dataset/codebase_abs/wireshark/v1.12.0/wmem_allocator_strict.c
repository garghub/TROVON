static inline void
F_1 ( T_1 * V_1 )
{
T_2 V_2 ;
T_3 * V_3 ;
V_3 = F_2 ( V_1 ) ;
for ( V_2 = 0 ; V_2 < V_4 ; V_2 ++ ) F_3 ( V_3 [ V_2 ] == V_5 ) ;
V_3 = F_4 ( V_1 ) ;
for ( V_2 = 0 ; V_2 < V_4 ; V_2 ++ ) F_3 ( V_3 [ V_2 ] == V_5 ) ;
}
static void *
F_5 ( void * V_6 , const T_4 V_7 )
{
T_5 * V_8 ;
T_1 * V_1 ;
T_2 V_2 ;
T_3 * V_3 ;
V_8 = ( T_5 * ) V_6 ;
V_1 = ( T_1 * ) F_6 ( NULL , F_7 ( V_7 ) ) ;
V_1 -> V_9 = V_7 ;
memset ( F_8 ( V_1 ) , V_10 , V_1 -> V_9 ) ;
V_3 = F_2 ( V_1 ) ;
for ( V_2 = 0 ; V_2 < V_4 ; V_2 ++ ) V_3 [ V_2 ] = V_5 ;
V_3 = F_4 ( V_1 ) ;
for ( V_2 = 0 ; V_2 < V_4 ; V_2 ++ ) V_3 [ V_2 ] = V_5 ;
if ( V_8 -> V_11 ) {
V_8 -> V_11 -> V_12 = V_1 ;
}
V_1 -> V_13 = V_8 -> V_11 ;
V_1 -> V_12 = NULL ;
V_8 -> V_11 = V_1 ;
return F_8 ( V_1 ) ;
}
static void
F_9 ( void * V_6 , void * V_14 )
{
T_5 * V_8 ;
T_1 * V_1 ;
V_8 = ( T_5 * ) V_6 ;
V_1 = F_10 ( V_14 ) ;
F_1 ( V_1 ) ;
if ( V_1 -> V_13 ) {
V_1 -> V_13 -> V_12 = V_1 -> V_12 ;
}
if ( V_1 -> V_12 ) {
V_1 -> V_12 -> V_13 = V_1 -> V_13 ;
}
else {
V_8 -> V_11 = V_1 -> V_13 ;
}
memset ( V_1 , V_15 , F_7 ( V_1 -> V_9 ) ) ;
F_11 ( NULL , V_1 ) ;
}
static void *
F_12 ( void * V_6 , void * V_14 , const T_4 V_7 )
{
T_1 * V_1 ;
void * V_16 ;
V_1 = F_10 ( V_14 ) ;
V_16 = F_5 ( V_6 , V_7 ) ;
if ( V_1 -> V_9 > V_7 ) {
memcpy ( V_16 , V_14 , V_7 ) ;
}
else {
memcpy ( V_16 , V_14 , V_1 -> V_9 ) ;
}
F_9 ( V_6 , V_14 ) ;
return V_16 ;
}
void
F_13 ( T_6 * V_8 )
{
T_5 * V_17 ;
T_1 * V_1 ;
if ( V_8 -> type != V_18 ) {
return;
}
V_17 = ( T_5 * ) V_8 -> V_6 ;
V_1 = V_17 -> V_11 ;
while ( V_1 ) {
F_1 ( V_1 ) ;
V_1 = V_1 -> V_13 ;
}
}
static void
F_14 ( void * V_6 )
{
T_5 * V_8 ;
V_8 = ( T_5 * ) V_6 ;
while ( V_8 -> V_11 ) {
F_9 ( V_6 , F_8 ( V_8 -> V_11 ) ) ;
}
}
static void
F_15 ( void * V_6 V_19 )
{
}
static void
F_16 ( void * V_6 )
{
F_11 ( NULL , V_6 ) ;
}
void
F_17 ( T_6 * V_8 )
{
T_5 * V_20 ;
V_20 = F_18 ( NULL , T_5 ) ;
V_8 -> V_21 = & F_5 ;
V_8 -> realloc = & F_12 ;
V_8 -> free = & F_9 ;
V_8 -> V_22 = & F_14 ;
V_8 -> V_23 = & F_15 ;
V_8 -> V_24 = & F_16 ;
V_8 -> V_6 = ( void * ) V_20 ;
V_20 -> V_11 = NULL ;
}
