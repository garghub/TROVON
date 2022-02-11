void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = NULL ;
V_2 -> V_4 = & V_2 -> V_3 ;
V_2 -> V_5 = 0 ;
V_2 -> V_6 = 0 ;
}
long F_2 ( struct V_1 * V_2 , long V_7 )
{
int V_8 = 0 ;
struct V_9 * * V_10 = & V_2 -> V_3 ;
for (; ; ) {
if ( ! * V_10 )
return V_8 ;
if ( ++ V_8 > V_7 )
return - 1 ;
V_10 = & ( * V_10 ) -> V_11 ;
}
}
struct V_9 * F_3 ( struct V_1 * V_2 )
{
struct V_9 * V_12 ;
V_12 = V_2 -> V_3 ;
if ( ! V_12 )
return NULL ;
V_2 -> V_5 -- ;
V_2 -> V_3 = V_12 -> V_11 ;
if ( ! V_2 -> V_3 )
V_2 -> V_4 = & V_2 -> V_3 ;
return V_12 ;
}
void F_4 ( struct V_13 * V_14 )
{
int V_15 ;
F_5 ( V_16 + 1 != F_6 ( V_14 -> V_17 ) ) ;
F_5 ( F_6 ( V_14 -> V_18 ) != F_6 ( V_14 -> V_17 ) ) ;
V_14 -> V_3 = NULL ;
for ( V_15 = 0 ; V_15 < V_19 ; V_15 ++ )
V_14 -> V_18 [ V_15 ] = & V_14 -> V_3 ;
V_14 -> V_5 = 0 ;
V_14 -> V_6 = 0 ;
}
void F_7 ( struct V_13 * V_14 )
{
F_8 ( ! F_9 ( V_14 ) ) ;
F_8 ( F_10 ( V_14 ) ) ;
F_8 ( F_11 ( V_14 ) ) ;
V_14 -> V_18 [ V_16 ] = NULL ;
}
bool F_12 ( struct V_13 * V_14 , int V_20 )
{
if ( V_20 == V_21 )
return & V_14 -> V_3 == V_14 -> V_18 [ V_21 ] ;
return V_14 -> V_18 [ V_20 - 1 ] == V_14 -> V_18 [ V_20 ] ;
}
bool F_13 ( struct V_13 * V_14 )
{
return F_14 ( V_14 ) &&
& V_14 -> V_3 != V_14 -> V_18 [ V_21 ] ;
}
bool F_15 ( struct V_13 * V_14 )
{
return F_14 ( V_14 ) &&
! F_16 ( V_14 , V_21 ) ;
}
struct V_9 * F_17 ( struct V_13 * V_14 )
{
unsigned long V_22 ;
int V_15 ;
struct V_9 * V_12 ;
F_18 ( V_22 ) ;
if ( ! F_13 ( V_14 ) ) {
F_19 ( V_22 ) ;
return NULL ;
}
V_12 = V_14 -> V_3 ;
F_20 ( ! V_12 ) ;
V_14 -> V_3 = V_12 -> V_11 ;
for ( V_15 = V_21 ; V_15 < V_19 ; V_15 ++ ) {
if ( V_14 -> V_18 [ V_15 ] != & V_12 -> V_11 )
break;
V_14 -> V_18 [ V_15 ] = & V_14 -> V_3 ;
}
F_21 () ;
F_22 ( V_14 -> V_5 , V_14 -> V_5 - 1 ) ;
F_19 ( V_22 ) ;
return V_12 ;
}
void F_23 ( struct V_13 * V_14 )
{
unsigned long V_22 ;
F_18 ( V_22 ) ;
V_14 -> V_6 -- ;
F_19 ( V_22 ) ;
}
struct V_9 * F_24 ( struct V_13 * V_14 )
{
if ( F_14 ( V_14 ) )
return V_14 -> V_3 ;
return NULL ;
}
struct V_9 * F_25 ( struct V_13 * V_14 )
{
if ( F_14 ( V_14 ) )
return * V_14 -> V_18 [ V_21 ] ;
return NULL ;
}
bool F_26 ( struct V_13 * V_14 )
{
return F_14 ( V_14 ) &&
! F_16 ( V_14 , V_23 ) ;
}
void F_27 ( struct V_13 * V_14 ,
struct V_9 * V_12 , bool V_24 )
{
F_22 ( V_14 -> V_5 , V_14 -> V_5 + 1 ) ;
if ( V_24 )
V_14 -> V_6 ++ ;
F_21 () ;
V_12 -> V_11 = NULL ;
* V_14 -> V_18 [ V_16 ] = V_12 ;
V_14 -> V_18 [ V_16 ] = & V_12 -> V_11 ;
}
bool F_28 ( struct V_13 * V_14 ,
struct V_9 * V_12 , bool V_24 )
{
int V_15 ;
if ( F_10 ( V_14 ) == 0 )
return false ;
F_22 ( V_14 -> V_5 , V_14 -> V_5 + 1 ) ;
if ( V_24 )
V_14 -> V_6 ++ ;
F_21 () ;
V_12 -> V_11 = NULL ;
for ( V_15 = V_16 ; V_15 > V_21 ; V_15 -- )
if ( V_14 -> V_18 [ V_15 ] != V_14 -> V_18 [ V_15 - 1 ] )
break;
* V_14 -> V_18 [ V_15 ] = V_12 ;
for (; V_15 <= V_16 ; V_15 ++ )
V_14 -> V_18 [ V_15 ] = & V_12 -> V_11 ;
return true ;
}
void F_29 ( struct V_13 * V_14 ,
struct V_1 * V_2 )
{
V_2 -> V_6 += V_14 -> V_6 ;
V_2 -> V_5 += V_14 -> V_5 ;
V_14 -> V_6 = 0 ;
F_22 ( V_14 -> V_5 , 0 ) ;
}
void F_30 ( struct V_13 * V_14 ,
struct V_1 * V_2 )
{
int V_15 ;
if ( ! F_13 ( V_14 ) )
return;
* V_2 -> V_4 = V_14 -> V_3 ;
V_14 -> V_3 = * V_14 -> V_18 [ V_21 ] ;
* V_14 -> V_18 [ V_21 ] = NULL ;
V_2 -> V_4 = V_14 -> V_18 [ V_21 ] ;
for ( V_15 = V_19 - 1 ; V_15 >= V_21 ; V_15 -- )
if ( V_14 -> V_18 [ V_15 ] == V_14 -> V_18 [ V_21 ] )
V_14 -> V_18 [ V_15 ] = & V_14 -> V_3 ;
}
void F_31 ( struct V_13 * V_14 ,
struct V_1 * V_2 )
{
int V_15 ;
if ( ! F_15 ( V_14 ) )
return;
* V_2 -> V_4 = * V_14 -> V_18 [ V_21 ] ;
V_2 -> V_4 = V_14 -> V_18 [ V_16 ] ;
* V_14 -> V_18 [ V_21 ] = NULL ;
for ( V_15 = V_21 + 1 ; V_15 < V_19 ; V_15 ++ )
V_14 -> V_18 [ V_15 ] = V_14 -> V_18 [ V_21 ] ;
}
void F_32 ( struct V_13 * V_14 ,
struct V_1 * V_2 )
{
V_14 -> V_6 += V_2 -> V_6 ;
F_22 ( V_14 -> V_5 , V_14 -> V_5 + V_2 -> V_5 ) ;
V_2 -> V_6 = 0 ;
V_2 -> V_5 = 0 ;
}
void F_33 ( struct V_13 * V_14 ,
struct V_1 * V_2 )
{
int V_15 ;
if ( ! V_2 -> V_3 )
return;
* V_2 -> V_4 = V_14 -> V_3 ;
V_14 -> V_3 = V_2 -> V_3 ;
for ( V_15 = V_21 ; V_15 < V_19 ; V_15 ++ )
if ( & V_14 -> V_3 == V_14 -> V_18 [ V_15 ] )
V_14 -> V_18 [ V_15 ] = V_2 -> V_4 ;
else
break;
V_2 -> V_3 = NULL ;
V_2 -> V_4 = & V_2 -> V_3 ;
}
void F_34 ( struct V_13 * V_14 ,
struct V_1 * V_2 )
{
if ( ! V_2 -> V_3 )
return;
* V_14 -> V_18 [ V_16 ] = V_2 -> V_3 ;
V_14 -> V_18 [ V_16 ] = V_2 -> V_4 ;
V_2 -> V_3 = NULL ;
V_2 -> V_4 = & V_2 -> V_3 ;
}
void F_35 ( struct V_13 * V_14 , unsigned long V_25 )
{
int V_15 , V_26 ;
F_8 ( ! F_14 ( V_14 ) ) ;
if ( F_16 ( V_14 , V_21 ) )
return;
for ( V_15 = V_27 ; V_15 < V_16 ; V_15 ++ ) {
if ( F_36 ( V_25 , V_14 -> V_17 [ V_15 ] ) )
break;
V_14 -> V_18 [ V_21 ] = V_14 -> V_18 [ V_15 ] ;
}
if ( V_15 == V_27 )
return;
for ( V_26 = V_27 ; V_26 < V_15 ; V_26 ++ )
V_14 -> V_18 [ V_26 ] = V_14 -> V_18 [ V_21 ] ;
for ( V_26 = V_27 ; V_15 < V_16 ; V_15 ++ , V_26 ++ ) {
if ( V_14 -> V_18 [ V_26 ] == V_14 -> V_18 [ V_16 ] )
break;
V_14 -> V_18 [ V_26 ] = V_14 -> V_18 [ V_15 ] ;
V_14 -> V_17 [ V_26 ] = V_14 -> V_17 [ V_15 ] ;
}
}
bool F_37 ( struct V_13 * V_14 , unsigned long V_25 )
{
int V_15 ;
F_8 ( ! F_14 ( V_14 ) ) ;
if ( F_16 ( V_14 , V_21 ) )
return false ;
for ( V_15 = V_23 ; V_15 > V_21 ; V_15 -- )
if ( V_14 -> V_18 [ V_15 ] != V_14 -> V_18 [ V_15 - 1 ] &&
F_36 ( V_14 -> V_17 [ V_15 ] , V_25 ) )
break;
if ( ++ V_15 >= V_16 )
return false ;
for (; V_15 < V_16 ; V_15 ++ ) {
V_14 -> V_18 [ V_15 ] = V_14 -> V_18 [ V_16 ] ;
V_14 -> V_17 [ V_15 ] = V_25 ;
}
return true ;
}
bool F_38 ( struct V_13 * V_14 ,
unsigned long V_25 )
{
int V_15 ;
for ( V_15 = V_27 ; V_15 < V_16 ; V_15 ++ )
if ( V_14 -> V_18 [ V_15 - 1 ] != V_14 -> V_18 [ V_15 ] &&
F_36 ( V_25 , V_14 -> V_17 [ V_15 ] ) )
return true ;
return false ;
}
