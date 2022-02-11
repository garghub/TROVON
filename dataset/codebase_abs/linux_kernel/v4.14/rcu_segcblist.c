void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = NULL ;
V_2 -> V_4 = & V_2 -> V_3 ;
V_2 -> V_5 = 0 ;
V_2 -> V_6 = 0 ;
}
struct V_7 * F_2 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
V_8 = V_2 -> V_3 ;
if ( ! V_8 )
return NULL ;
V_2 -> V_5 -- ;
V_2 -> V_3 = V_8 -> V_9 ;
if ( ! V_2 -> V_3 )
V_2 -> V_4 = & V_2 -> V_3 ;
return V_8 ;
}
void F_3 ( struct V_10 * V_11 )
{
int V_12 ;
F_4 ( V_13 + 1 != F_5 ( V_11 -> V_14 ) ) ;
F_4 ( F_5 ( V_11 -> V_15 ) != F_5 ( V_11 -> V_14 ) ) ;
V_11 -> V_3 = NULL ;
for ( V_12 = 0 ; V_12 < V_16 ; V_12 ++ )
V_11 -> V_15 [ V_12 ] = & V_11 -> V_3 ;
V_11 -> V_5 = 0 ;
V_11 -> V_6 = 0 ;
}
void F_6 ( struct V_10 * V_11 )
{
F_7 ( ! F_8 ( V_11 ) ) ;
F_7 ( F_9 ( V_11 ) ) ;
F_7 ( F_10 ( V_11 ) ) ;
V_11 -> V_15 [ V_13 ] = NULL ;
}
bool F_11 ( struct V_10 * V_11 )
{
return F_12 ( V_11 ) &&
& V_11 -> V_3 != V_11 -> V_15 [ V_17 ] ;
}
bool F_13 ( struct V_10 * V_11 )
{
return F_12 ( V_11 ) &&
! F_14 ( V_11 , V_17 ) ;
}
struct V_7 * F_15 ( struct V_10 * V_11 )
{
if ( F_12 ( V_11 ) )
return V_11 -> V_3 ;
return NULL ;
}
struct V_7 * F_16 ( struct V_10 * V_11 )
{
if ( F_12 ( V_11 ) )
return * V_11 -> V_15 [ V_17 ] ;
return NULL ;
}
void F_17 ( struct V_10 * V_11 ,
struct V_7 * V_8 , bool V_18 )
{
F_18 ( V_11 -> V_5 , V_11 -> V_5 + 1 ) ;
if ( V_18 )
V_11 -> V_6 ++ ;
F_19 () ;
V_8 -> V_9 = NULL ;
* V_11 -> V_15 [ V_13 ] = V_8 ;
V_11 -> V_15 [ V_13 ] = & V_8 -> V_9 ;
}
bool F_20 ( struct V_10 * V_11 ,
struct V_7 * V_8 , bool V_18 )
{
int V_12 ;
if ( F_9 ( V_11 ) == 0 )
return false ;
F_18 ( V_11 -> V_5 , V_11 -> V_5 + 1 ) ;
if ( V_18 )
V_11 -> V_6 ++ ;
F_19 () ;
V_8 -> V_9 = NULL ;
for ( V_12 = V_13 ; V_12 > V_17 ; V_12 -- )
if ( V_11 -> V_15 [ V_12 ] != V_11 -> V_15 [ V_12 - 1 ] )
break;
* V_11 -> V_15 [ V_12 ] = V_8 ;
for (; V_12 <= V_13 ; V_12 ++ )
V_11 -> V_15 [ V_12 ] = & V_8 -> V_9 ;
return true ;
}
void F_21 ( struct V_10 * V_11 ,
struct V_1 * V_2 )
{
V_2 -> V_6 += V_11 -> V_6 ;
V_2 -> V_5 += V_11 -> V_5 ;
V_11 -> V_6 = 0 ;
F_18 ( V_11 -> V_5 , 0 ) ;
}
void F_22 ( struct V_10 * V_11 ,
struct V_1 * V_2 )
{
int V_12 ;
if ( ! F_11 ( V_11 ) )
return;
* V_2 -> V_4 = V_11 -> V_3 ;
V_11 -> V_3 = * V_11 -> V_15 [ V_17 ] ;
* V_11 -> V_15 [ V_17 ] = NULL ;
V_2 -> V_4 = V_11 -> V_15 [ V_17 ] ;
for ( V_12 = V_16 - 1 ; V_12 >= V_17 ; V_12 -- )
if ( V_11 -> V_15 [ V_12 ] == V_11 -> V_15 [ V_17 ] )
V_11 -> V_15 [ V_12 ] = & V_11 -> V_3 ;
}
void F_23 ( struct V_10 * V_11 ,
struct V_1 * V_2 )
{
int V_12 ;
if ( ! F_13 ( V_11 ) )
return;
* V_2 -> V_4 = * V_11 -> V_15 [ V_17 ] ;
V_2 -> V_4 = V_11 -> V_15 [ V_13 ] ;
* V_11 -> V_15 [ V_17 ] = NULL ;
for ( V_12 = V_17 + 1 ; V_12 < V_16 ; V_12 ++ )
V_11 -> V_15 [ V_12 ] = V_11 -> V_15 [ V_17 ] ;
}
void F_24 ( struct V_10 * V_11 ,
struct V_1 * V_2 )
{
V_11 -> V_6 += V_2 -> V_6 ;
F_18 ( V_11 -> V_5 , V_11 -> V_5 + V_2 -> V_5 ) ;
V_2 -> V_6 = 0 ;
V_2 -> V_5 = 0 ;
}
void F_25 ( struct V_10 * V_11 ,
struct V_1 * V_2 )
{
int V_12 ;
if ( ! V_2 -> V_3 )
return;
* V_2 -> V_4 = V_11 -> V_3 ;
V_11 -> V_3 = V_2 -> V_3 ;
for ( V_12 = V_17 ; V_12 < V_16 ; V_12 ++ )
if ( & V_11 -> V_3 == V_11 -> V_15 [ V_12 ] )
V_11 -> V_15 [ V_12 ] = V_2 -> V_4 ;
else
break;
V_2 -> V_3 = NULL ;
V_2 -> V_4 = & V_2 -> V_3 ;
}
void F_26 ( struct V_10 * V_11 ,
struct V_1 * V_2 )
{
if ( ! V_2 -> V_3 )
return;
* V_11 -> V_15 [ V_13 ] = V_2 -> V_3 ;
V_11 -> V_15 [ V_13 ] = V_2 -> V_4 ;
V_2 -> V_3 = NULL ;
V_2 -> V_4 = & V_2 -> V_3 ;
}
void F_27 ( struct V_10 * V_11 , unsigned long V_19 )
{
int V_12 , V_20 ;
F_7 ( ! F_12 ( V_11 ) ) ;
if ( F_14 ( V_11 , V_17 ) )
return;
for ( V_12 = V_21 ; V_12 < V_13 ; V_12 ++ ) {
if ( F_28 ( V_19 , V_11 -> V_14 [ V_12 ] ) )
break;
V_11 -> V_15 [ V_17 ] = V_11 -> V_15 [ V_12 ] ;
}
if ( V_12 == V_21 )
return;
for ( V_20 = V_21 ; V_20 < V_12 ; V_20 ++ )
V_11 -> V_15 [ V_20 ] = V_11 -> V_15 [ V_17 ] ;
for ( V_20 = V_21 ; V_12 < V_13 ; V_12 ++ , V_20 ++ ) {
if ( V_11 -> V_15 [ V_20 ] == V_11 -> V_15 [ V_13 ] )
break;
V_11 -> V_15 [ V_20 ] = V_11 -> V_15 [ V_12 ] ;
V_11 -> V_14 [ V_20 ] = V_11 -> V_14 [ V_12 ] ;
}
}
bool F_29 ( struct V_10 * V_11 , unsigned long V_19 )
{
int V_12 ;
F_7 ( ! F_12 ( V_11 ) ) ;
if ( F_14 ( V_11 , V_17 ) )
return false ;
for ( V_12 = V_22 ; V_12 > V_17 ; V_12 -- )
if ( V_11 -> V_15 [ V_12 ] != V_11 -> V_15 [ V_12 - 1 ] &&
F_28 ( V_11 -> V_14 [ V_12 ] , V_19 ) )
break;
if ( ++ V_12 >= V_13 )
return false ;
for (; V_12 < V_13 ; V_12 ++ ) {
V_11 -> V_15 [ V_12 ] = V_11 -> V_15 [ V_13 ] ;
V_11 -> V_14 [ V_12 ] = V_19 ;
}
return true ;
}
bool F_30 ( struct V_10 * V_11 ,
unsigned long V_19 )
{
int V_12 ;
for ( V_12 = V_21 ; V_12 < V_13 ; V_12 ++ )
if ( V_11 -> V_15 [ V_12 - 1 ] != V_11 -> V_15 [ V_12 ] &&
F_28 ( V_19 , V_11 -> V_14 [ V_12 ] ) )
return true ;
return false ;
}
void F_31 ( struct V_10 * V_23 ,
struct V_10 * V_24 )
{
struct V_1 V_25 ;
struct V_1 V_26 ;
F_1 ( & V_25 ) ;
F_1 ( & V_26 ) ;
F_21 ( V_24 , & V_25 ) ;
F_22 ( V_24 , & V_25 ) ;
F_23 ( V_24 , & V_26 ) ;
F_24 ( V_23 , & V_25 ) ;
F_25 ( V_23 , & V_25 ) ;
F_26 ( V_23 , & V_26 ) ;
F_3 ( V_24 ) ;
}
