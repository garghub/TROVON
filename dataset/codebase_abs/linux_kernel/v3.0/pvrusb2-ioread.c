static int F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
V_2 -> V_4 = NULL ;
F_2 ( & V_2 -> V_5 ) ;
for ( V_3 = 0 ; V_3 < V_6 ; V_3 ++ ) {
V_2 -> V_7 [ V_3 ] = F_3 ( V_8 , V_9 ) ;
if ( ! ( V_2 -> V_7 [ V_3 ] ) ) break;
}
if ( V_3 < V_6 ) {
for ( V_3 = 0 ; V_3 < V_6 ; V_3 ++ ) {
if ( ! ( V_2 -> V_7 [ V_3 ] ) ) continue;
F_4 ( V_2 -> V_7 [ V_3 ] ) ;
}
return - V_10 ;
}
return 0 ;
}
static void F_5 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
F_6 ( V_2 , NULL ) ;
for ( V_3 = 0 ; V_3 < V_6 ; V_3 ++ ) {
if ( ! ( V_2 -> V_7 [ V_3 ] ) ) continue;
F_4 ( V_2 -> V_7 [ V_3 ] ) ;
}
}
struct V_1 * F_7 ( void )
{
struct V_1 * V_2 ;
V_2 = F_8 ( sizeof( * V_2 ) , V_9 ) ;
if ( ! V_2 ) return NULL ;
F_9 ( V_11 , L_1 , V_2 ) ;
if ( F_1 ( V_2 ) < 0 ) {
F_4 ( V_2 ) ;
return NULL ;
}
return V_2 ;
}
void F_10 ( struct V_1 * V_2 )
{
if ( ! V_2 ) return;
F_5 ( V_2 ) ;
F_9 ( V_11 , L_2 , V_2 ) ;
if ( V_2 -> V_12 ) {
F_4 ( V_2 -> V_12 ) ;
V_2 -> V_12 = NULL ;
}
F_4 ( V_2 ) ;
}
void F_11 ( struct V_1 * V_2 ,
const char * V_12 ,
unsigned int V_13 )
{
if ( ! V_2 ) return;
if ( ! V_12 ) V_13 = 0 ;
if ( ( V_13 == V_2 -> V_13 ) &&
( ( ! V_13 ) ||
( ! memcmp ( V_12 , V_2 -> V_12 , V_13 ) ) ) ) return;
if ( V_13 != V_2 -> V_13 ) {
if ( V_2 -> V_12 ) {
F_4 ( V_2 -> V_12 ) ;
V_2 -> V_12 = NULL ;
}
V_2 -> V_13 = 0 ;
if ( V_13 ) {
V_2 -> V_12 = F_3 ( V_13 , V_9 ) ;
if ( V_2 -> V_12 ) {
V_2 -> V_13 = V_13 ;
}
}
}
if ( ! V_2 -> V_13 ) return;
memcpy ( V_2 -> V_12 , V_12 , V_2 -> V_13 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_14 ) ) return;
F_9 ( V_15 ,
L_3 , V_2 ) ;
F_13 ( V_2 -> V_4 ) ;
V_2 -> V_16 = NULL ;
V_2 -> V_17 = NULL ;
V_2 -> V_18 = 0 ;
V_2 -> V_19 = 0 ;
V_2 -> V_14 = 0 ;
V_2 -> V_20 = 0 ;
V_2 -> V_21 = 0 ;
if ( V_2 -> V_22 ) {
F_9 ( V_23 ,
L_4 ) ;
V_2 -> V_22 = 0 ;
}
}
static int F_14 ( struct V_1 * V_2 )
{
int V_24 ;
struct V_25 * V_26 ;
if ( V_2 -> V_14 ) return 0 ;
if ( ! ( V_2 -> V_4 ) ) return 0 ;
F_9 ( V_15 ,
L_5 , V_2 ) ;
while ( ( V_26 = F_15 ( V_2 -> V_4 ) ) != NULL ) {
V_24 = F_16 ( V_26 ) ;
if ( V_24 < 0 ) {
F_9 ( V_23 ,
L_6
L_7
L_8 ,
V_2 , V_24 ) ;
F_12 ( V_2 ) ;
return V_24 ;
}
}
V_2 -> V_14 = ! 0 ;
V_2 -> V_16 = NULL ;
V_2 -> V_17 = NULL ;
V_2 -> V_18 = 0 ;
V_2 -> V_19 = 0 ;
V_2 -> V_20 = 0 ;
if ( V_2 -> V_13 ) {
F_9 ( V_23 ,
L_9 ) ;
V_2 -> V_22 = 1 ;
V_2 -> V_27 = 0 ;
V_2 -> V_28 = 0 ;
}
V_2 -> V_21 = 0 ;
return 0 ;
}
struct V_29 * F_17 ( struct V_1 * V_2 )
{
return V_2 -> V_4 ;
}
int F_6 ( struct V_1 * V_2 , struct V_29 * V_30 )
{
int V_31 ;
unsigned int V_3 ;
struct V_25 * V_26 ;
F_18 ( & V_2 -> V_5 ) ; do {
if ( V_2 -> V_4 ) {
F_9 ( V_15 ,
L_6
L_10 , V_2 ) ;
F_12 ( V_2 ) ;
F_13 ( V_2 -> V_4 ) ;
if ( F_19 ( V_2 -> V_4 ) ) {
F_20 ( V_2 -> V_4 , 0 ) ;
}
V_2 -> V_4 = NULL ;
}
if ( V_30 ) {
F_9 ( V_15 ,
L_6
L_11 , V_2 ) ;
F_13 ( V_30 ) ;
V_31 = F_20 ( V_30 , V_6 ) ;
if ( V_31 < 0 ) {
F_21 ( & V_2 -> V_5 ) ;
return V_31 ;
}
for ( V_3 = 0 ; V_3 < V_6 ; V_3 ++ ) {
V_26 = F_22 ( V_30 , V_3 ) ;
F_23 ( V_26 ,
V_2 -> V_7 [ V_3 ] ,
V_8 ) ;
}
V_2 -> V_4 = V_30 ;
}
} while ( 0 ); F_21 ( & V_2 -> V_5 ) ;
return 0 ;
}
int F_24 ( struct V_1 * V_2 , int V_32 )
{
int V_31 = 0 ;
if ( ( ! V_32 ) == ( ! ( V_2 -> V_14 ) ) ) return V_31 ;
F_18 ( & V_2 -> V_5 ) ; do {
if ( V_32 ) {
V_31 = F_14 ( V_2 ) ;
} else {
F_12 ( V_2 ) ;
}
} while ( 0 ); F_21 ( & V_2 -> V_5 ) ;
return V_31 ;
}
static int F_25 ( struct V_1 * V_2 )
{
int V_24 ;
while ( V_2 -> V_18 <= V_2 -> V_19 ) {
if ( V_2 -> V_16 ) {
V_24 = F_16 ( V_2 -> V_16 ) ;
if ( V_24 < 0 ) {
F_9 ( V_23 ,
L_6
L_12
L_13 ,
V_2 , V_24 ) ;
F_12 ( V_2 ) ;
return 0 ;
}
V_2 -> V_16 = NULL ;
V_2 -> V_17 = NULL ;
V_2 -> V_18 = 0 ;
V_2 -> V_19 = 0 ;
}
V_2 -> V_16 = F_26 ( V_2 -> V_4 ) ;
if ( ! V_2 -> V_16 ) break;
V_2 -> V_18 = F_27 ( V_2 -> V_16 ) ;
if ( ! V_2 -> V_18 ) {
V_24 = F_28 ( V_2 -> V_16 ) ;
if ( V_24 < 0 ) {
F_9 ( V_23 ,
L_6
L_12
L_14 ,
V_2 , V_24 ) ;
F_12 ( V_2 ) ;
return 0 ;
}
continue;
}
V_2 -> V_19 = 0 ;
V_2 -> V_17 = V_2 -> V_7 [
F_29 ( V_2 -> V_16 ) ] ;
}
return ! 0 ;
}
static void F_30 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
if ( ! V_2 -> V_14 ) return;
if ( V_2 -> V_22 != 1 ) return;
F_18 ( & V_2 -> V_5 ) ; while ( 1 ) {
if ( ! F_25 ( V_2 ) ) break;
if ( ! V_2 -> V_18 ) break;
for ( V_3 = V_2 -> V_19 ; V_3 < V_2 -> V_18 ; V_3 ++ ) {
if ( V_2 -> V_28 >= V_2 -> V_13 ) break;
if ( V_2 -> V_17 [ V_3 ] ==
V_2 -> V_12 [ V_2 -> V_28 ] ) {
( V_2 -> V_28 ) ++ ;
} else {
V_2 -> V_28 = 0 ;
}
}
V_2 -> V_19 += V_3 ;
V_2 -> V_27 += V_3 ;
if ( V_2 -> V_28 >= V_2 -> V_13 ) {
V_2 -> V_27 -= V_2 -> V_13 ;
F_9 ( V_23 ,
L_6
L_15 ,
V_2 -> V_27 ) ;
V_2 -> V_22 = 2 ;
V_2 -> V_28 = 0 ;
break;
}
if ( V_2 -> V_19 < V_2 -> V_18 ) {
F_9 ( V_33 ,
L_16
L_17 ,
V_2 -> V_18 , V_2 -> V_19 ) ;
break;
}
continue;
} F_21 ( & V_2 -> V_5 ) ;
}
int F_31 ( struct V_1 * V_2 )
{
int V_31 ;
if ( ! ( V_2 -> V_14 ) ) {
return - V_34 ;
}
if ( V_2 -> V_22 == 1 ) {
F_30 ( V_2 ) ;
if ( V_2 -> V_22 == 1 ) return - V_35 ;
}
V_31 = 0 ;
if ( V_2 -> V_20 ) {
if ( ! F_32 ( V_2 -> V_4 ) ) {
V_31 = - V_35 ;
}
} else {
if ( F_32 ( V_2 -> V_4 ) < V_6 / 2 ) {
V_31 = - V_35 ;
}
}
if ( ( ! ( V_2 -> V_21 ) ) != ( ! ( V_31 == 0 ) ) ) {
V_2 -> V_21 = ( V_31 == 0 ) ;
F_9 ( V_23 ,
L_18 ,
V_2 -> V_21 ? L_19 : L_20 ) ;
}
return V_31 ;
}
int F_33 ( struct V_1 * V_2 , void T_1 * V_36 , unsigned int V_37 )
{
unsigned int V_38 ;
unsigned int V_39 ;
const char * V_40 ;
int V_24 ;
int V_31 = 0 ;
unsigned int V_41 = V_37 ;
if ( ! V_37 ) {
F_9 ( V_42 ,
L_21
L_22 , V_2 ) ;
return 0 ;
}
V_24 = F_31 ( V_2 ) ;
if ( V_24 < 0 ) return V_24 ;
V_2 -> V_20 = ! 0 ;
F_18 ( & V_2 -> V_5 ) ; do {
V_38 = 0 ;
if ( ! V_36 ) V_37 = 0 ;
while ( 1 ) {
if ( ! F_25 ( V_2 ) ) {
V_31 = - V_34 ;
break;
}
if ( ! V_37 ) break;
if ( V_2 -> V_22 == 2 ) {
V_40 = V_2 -> V_12 + V_2 -> V_28 ;
V_39 = V_2 -> V_13 - V_2 -> V_28 ;
} else {
V_40 = V_2 -> V_17 + V_2 -> V_19 ;
V_39 = V_2 -> V_18 - V_2 -> V_19 ;
}
if ( ! V_39 ) break;
if ( V_39 > V_37 ) V_39 = V_37 ;
if ( F_34 ( V_36 , V_40 , V_39 ) ) {
V_31 = - V_43 ;
break;
}
V_37 -= V_39 ;
V_36 += V_39 ;
V_38 += V_39 ;
if ( V_2 -> V_22 == 2 ) {
V_2 -> V_28 += V_39 ;
if ( V_2 -> V_28 >= V_2 -> V_13 ) {
F_9 ( V_23 ,
L_6
L_23 ) ;
V_2 -> V_22 = 0 ;
}
} else {
V_2 -> V_19 += V_39 ;
}
}
} while ( 0 ); F_21 ( & V_2 -> V_5 ) ;
if ( ! V_31 ) {
if ( V_38 ) {
V_31 = V_38 ;
} else {
V_31 = - V_35 ;
}
}
F_9 ( V_23 ,
L_24
L_25 ,
V_2 , V_41 , V_31 ) ;
return V_31 ;
}
