static inline int F_1 ( unsigned long V_1 )
{
switch ( V_1 ) {
case 32ul << 20 :
if ( F_2 ( V_2 ) )
return 8 ;
return - 1 ;
case 64ul << 20 :
return 3 ;
case 128ul << 20 :
return 7 ;
case 256ul << 20 :
return 4 ;
case 1ul << 30 :
return 2 ;
case 16ul << 30 :
return 1 ;
case 256ul << 30 :
return 0 ;
default:
return - 1 ;
}
}
static int T_1 F_3 ( char * V_3 )
{
if ( ! V_3 )
return 1 ;
V_4 = F_4 ( V_3 , & V_3 ) ;
return 0 ;
}
static int T_1 F_5 ( char * V_3 )
{
if ( ! V_3 )
return 1 ;
V_5 = F_6 ( V_3 , NULL , 0 ) ;
return 0 ;
}
struct V_6 * F_7 ( void )
{
return F_8 ( V_7 ) ;
}
void F_9 ( struct V_6 * V_8 )
{
F_10 ( V_8 ) ;
}
static int T_1 F_11 ( char * V_3 )
{
if ( ! V_3 )
return 1 ;
V_9 = F_6 ( V_3 , NULL , 0 ) ;
return 0 ;
}
struct V_6 * F_12 ( void )
{
return F_8 ( V_10 ) ;
}
void F_13 ( struct V_6 * V_11 )
{
F_10 ( V_11 ) ;
}
static void T_1 F_14 ( T_2 V_12 , int V_13 , int type )
{
unsigned long V_14 ;
unsigned long V_15 , V_16 ;
void * V_17 ;
struct V_18 * V_19 ;
const char * V_20 ;
struct V_6 * V_21 ;
if ( ! V_13 )
return;
V_20 = ( type == V_7 ) ? L_1 : L_2 ;
V_16 = V_12 >> V_22 ;
V_21 = F_15 ( V_13 * sizeof( struct V_6 ) ) ;
for ( V_14 = 0 ; V_14 < V_13 ; ++ V_14 ) {
V_17 = F_16 ( V_12 , V_12 ) ;
F_17 ( L_3 , V_20 , V_17 ,
V_12 >> 20 ) ;
V_21 [ V_14 ] . V_23 = V_17 ;
V_21 [ V_14 ] . V_24 = F_18 ( V_17 ) >> V_22 ;
V_21 [ V_14 ] . V_16 = V_16 ;
V_21 [ V_14 ] . type = type ;
F_19 ( & V_21 [ V_14 ] . V_25 , & V_26 ) ;
F_20 ( & V_21 [ V_14 ] . V_27 , 0 ) ;
V_19 = F_21 ( V_21 [ V_14 ] . V_24 ) ;
for ( V_15 = 0 ; V_15 < V_16 ; ++ V_15 ) {
F_22 ( & V_19 -> V_28 ) ;
++ V_19 ;
}
}
}
static struct V_6 * F_8 ( int type )
{
struct V_6 * V_8 , * V_29 ;
V_29 = NULL ;
F_23 ( & V_30 ) ;
F_24 (ri, &free_linears, list) {
if ( V_8 -> type != type )
continue;
F_25 ( & V_8 -> V_25 ) ;
F_22 ( & V_8 -> V_27 ) ;
memset ( V_8 -> V_23 , 0 , V_8 -> V_16 << V_22 ) ;
V_29 = V_8 ;
break;
}
F_26 ( & V_30 ) ;
return V_29 ;
}
static void F_10 ( struct V_6 * V_8 )
{
if ( F_27 ( & V_8 -> V_27 ) ) {
F_23 ( & V_30 ) ;
F_19 ( & V_8 -> V_25 , & V_26 ) ;
F_26 ( & V_30 ) ;
}
}
void T_1 F_28 ( void )
{
F_14 ( 1 << V_31 , V_9 , V_10 ) ;
if ( ! F_2 ( V_32 ) ||
! F_2 ( V_33 ) )
return;
if ( ! V_4 || ! V_5 )
return;
if ( F_1 ( V_4 ) < 0 ) {
F_29 ( L_4 , V_4 ) ;
return;
}
F_14 ( V_4 , V_5 , V_7 ) ;
}
