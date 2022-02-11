static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_2 ( L_1 , V_2 ) ;
V_4 = F_3 ( sizeof( * V_4 ) , V_5 ) ;
if ( ! V_4 )
return - V_6 ;
F_4 ( & V_4 -> V_7 ) ;
V_2 -> V_8 = V_4 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_8 ;
F_2 ( L_1 , V_2 ) ;
F_6 ( & V_4 -> V_7 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_8 ;
V_2 -> V_8 = NULL ;
F_2 ( L_1 , V_2 ) ;
F_6 ( & V_4 -> V_7 ) ;
F_8 ( V_4 -> V_9 ) ;
V_2 -> V_8 = NULL ;
F_9 ( V_4 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_3 * V_4 = V_2 -> V_8 ;
F_2 ( L_2 , V_2 , V_11 ) ;
memcpy ( F_11 ( V_11 , 1 ) , & F_12 ( V_11 ) , 1 ) ;
F_13 ( & V_4 -> V_7 , V_11 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , const void * V_12 , int V_13 )
{
struct V_3 * V_4 = V_2 -> V_8 ;
if ( ! F_15 ( V_14 , & V_2 -> V_15 ) )
return - V_16 ;
V_4 -> V_9 = F_16 ( V_2 -> V_17 , V_4 -> V_9 , V_12 , V_13 ,
V_18 , F_17 ( V_18 ) ) ;
if ( F_18 ( V_4 -> V_9 ) ) {
int V_19 = F_19 ( V_4 -> V_9 ) ;
F_20 ( L_3 , V_2 -> V_17 -> V_20 , V_19 ) ;
V_4 -> V_9 = NULL ;
return V_19 ;
}
return V_13 ;
}
static struct V_10 * F_21 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_8 ;
return F_22 ( & V_4 -> V_7 ) ;
}
int T_1 F_23 ( void )
{
return F_24 ( & V_21 ) ;
}
int T_2 F_25 ( void )
{
return F_26 ( & V_21 ) ;
}
struct V_10 * F_16 ( struct V_22 * V_17 , struct V_10 * V_11 ,
const unsigned char * V_23 , int V_13 ,
const struct V_24 * V_25 , int V_26 )
{
struct V_1 * V_2 = F_27 ( V_17 ) ;
T_3 V_27 = V_2 -> V_27 ? V_2 -> V_27 : 1 ;
while ( V_13 ) {
int V_28 , V_29 ;
for (; V_2 -> V_30 && V_13 > 0 ; V_2 -> V_30 -- ) {
V_13 -- ;
V_23 ++ ;
}
if ( ! V_13 )
break;
if ( ! V_11 ) {
for ( V_28 = 0 ; V_28 < V_26 ; V_28 ++ ) {
if ( V_23 [ 0 ] != ( & V_25 [ V_28 ] ) -> type )
continue;
V_11 = F_28 ( ( & V_25 [ V_28 ] ) -> V_31 ,
V_32 ) ;
if ( ! V_11 )
return F_29 ( - V_6 ) ;
F_12 ( V_11 ) = ( & V_25 [ V_28 ] ) -> type ;
F_30 ( V_11 ) = ( & V_25 [ V_28 ] ) -> V_33 ;
break;
}
if ( ! V_11 )
return F_29 ( - V_34 ) ;
V_13 -= 1 ;
V_23 += 1 ;
}
V_29 = F_31 ( V_35 , F_30 ( V_11 ) - V_11 -> V_29 , V_13 ) ;
F_32 ( V_11 , V_23 , V_29 ) ;
V_13 -= V_29 ;
V_23 += V_29 ;
if ( V_11 -> V_29 < F_30 ( V_11 ) )
continue;
for ( V_28 = 0 ; V_28 < V_26 ; V_28 ++ ) {
if ( F_12 ( V_11 ) == ( & V_25 [ V_28 ] ) -> type )
break;
}
if ( V_28 >= V_26 ) {
F_8 ( V_11 ) ;
return F_29 ( - V_34 ) ;
}
if ( V_11 -> V_29 == ( & V_25 [ V_28 ] ) -> V_33 ) {
T_4 V_36 ;
switch ( ( & V_25 [ V_28 ] ) -> V_37 ) {
case 0 :
V_36 = 0 ;
break;
case 1 :
V_36 = V_11 -> V_12 [ ( & V_25 [ V_28 ] ) -> V_38 ] ;
F_30 ( V_11 ) += V_36 ;
if ( F_33 ( V_11 ) < V_36 ) {
F_8 ( V_11 ) ;
return F_29 ( - V_39 ) ;
}
break;
case 2 :
V_36 = F_34 ( V_11 -> V_12 +
( & V_25 [ V_28 ] ) -> V_38 ) ;
F_30 ( V_11 ) += V_36 ;
if ( F_33 ( V_11 ) < V_36 ) {
F_8 ( V_11 ) ;
return F_29 ( - V_39 ) ;
}
break;
default:
F_8 ( V_11 ) ;
return F_29 ( - V_34 ) ;
}
if ( ! V_36 ) {
V_2 -> V_30 = ( V_11 -> V_29 - 1 ) % V_27 ;
V_2 -> V_30 = ( V_27 - V_2 -> V_30 ) % V_27 ;
( & V_25 [ V_28 ] ) -> V_40 ( V_17 , V_11 ) ;
V_11 = NULL ;
}
} else {
V_2 -> V_30 = ( V_11 -> V_29 - 1 ) % V_27 ;
V_2 -> V_30 = ( V_27 - V_2 -> V_30 ) % V_27 ;
( & V_25 [ V_28 ] ) -> V_40 ( V_17 , V_11 ) ;
V_11 = NULL ;
}
}
return V_11 ;
}
