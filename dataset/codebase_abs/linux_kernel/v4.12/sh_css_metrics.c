void
F_1 ( void )
{
V_1 . V_2 . V_3 ++ ;
}
static void
F_2 ( struct V_4 * V_5 )
{
unsigned V_6 ;
assert ( V_5 != NULL ) ;
for ( V_6 = 0 ; V_6 < V_5 -> V_7 ; V_6 ++ ) {
V_5 -> V_8 [ V_6 ] = 0 ;
V_5 -> V_9 [ V_6 ] = 0 ;
V_5 -> V_10 [ V_6 ] = 0xFFFF ;
}
}
void
F_3 ( bool V_11 )
{
V_12 = V_11 ;
}
static void
F_4 ( struct V_4 * V_5 , unsigned V_7 )
{
assert ( V_5 != NULL ) ;
if ( V_5 -> V_7 )
return;
if ( V_5 -> V_8 )
return;
V_5 -> V_8 = F_5 ( V_7 * sizeof( * V_5 -> V_8 ) ) ;
if ( ! V_5 -> V_8 )
return;
V_5 -> V_9 = F_5 ( V_7 * sizeof( * V_5 -> V_9 ) ) ;
if ( ! V_5 -> V_9 )
return;
V_5 -> V_10 = F_5 ( V_7 * sizeof( * V_5 -> V_10 ) ) ;
if ( ! V_5 -> V_10 )
return;
V_5 -> V_7 = V_7 ;
F_2 ( V_5 ) ;
}
static void
F_6 ( struct V_13 * * V_14 ,
struct V_13 * V_15 )
{
assert ( V_14 != NULL ) ;
assert ( * V_14 != NULL ) ;
assert ( V_15 != NULL ) ;
for (; * V_14 ; V_14 = & ( * V_14 ) -> V_16 )
if ( * V_14 == V_15 )
return;
* V_14 = V_15 ;
V_15 -> V_16 = NULL ;
}
void
F_7 ( struct V_13 * V_15 )
{
assert ( V_15 != NULL ) ;
if ( ! V_12 )
return;
V_17 = & V_15 -> V_17 ;
V_18 = & V_15 -> V_18 ;
F_4 ( V_17 , V_19 ) ;
F_4 ( V_18 , V_20 ) ;
F_6 ( & V_1 . V_21 , V_15 ) ;
}
void
F_8 ( void )
{
bool V_9 ;
unsigned int V_22 ;
unsigned int V_10 ;
#if V_23
unsigned int V_24 = 0 ;
unsigned int V_25 = 0 ;
unsigned int V_26 = 0 ;
#endif
#if V_27
int V_6 ;
unsigned int V_28 [ V_29 ] ;
for ( V_6 = 0 ; V_6 < V_29 ; V_6 ++ )
V_28 [ V_6 ] = 0 ;
#endif
if ( ! V_12 )
return;
if ( V_17 ) {
#if V_23
F_9 ( V_30 , V_31 , V_32 ) ;
#endif
V_10 = F_10 ( V_30 , V_33 ) ;
#if V_27
for ( V_6 = 0 ; V_6 < V_29 ; V_6 ++ )
V_28 [ V_6 ] = F_10 ( V_30 , V_34 ) ;
#else
V_22 = F_10 ( V_30 , V_34 ) ;
#endif
#if V_23
F_9 ( V_30 , V_31 , V_35 ) ;
#endif
V_17 -> V_10 [ V_22 ] &= V_10 ;
V_9 = ( V_10 != 0x7FF ) ;
if ( V_9 )
V_17 -> V_9 [ V_22 ] ++ ;
else
V_17 -> V_8 [ V_22 ] ++ ;
}
if ( V_18 && 0 ) {
V_10 = F_11 ( V_36 , V_37 ) ;
V_22 = F_11 ( V_36 , V_38 ) ;
V_18 -> V_10 [ V_22 ] &= V_10 ;
V_9 = ( V_10 != 0x7FF ) ;
if ( V_9 )
V_18 -> V_9 [ V_22 ] ++ ;
else
V_18 -> V_8 [ V_22 ] ++ ;
}
}
