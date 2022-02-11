static int T_1 F_1 ( char * V_1 )
{
if ( ! V_1 )
return 1 ;
V_2 = F_2 ( V_1 , & V_1 ) ;
return 0 ;
}
static int T_1 F_3 ( char * V_1 )
{
if ( ! V_1 )
return 1 ;
V_3 = F_4 ( V_1 , NULL , 0 ) ;
return 0 ;
}
static inline int F_5 ( unsigned long V_4 )
{
switch ( V_4 ) {
case 32ul << 20 :
if ( F_6 ( V_5 ) )
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
void F_7 ( void )
{
unsigned long V_6 ;
unsigned long V_7 , V_8 ;
void * V_9 ;
struct V_10 * V_11 ;
if ( ! F_6 ( V_12 ) ||
! F_6 ( V_13 ) )
return;
if ( ! V_2 || ! V_3 )
return;
if ( F_5 ( V_2 ) < 0 ) {
F_8 ( L_1 , V_2 ) ;
return;
}
V_8 = V_2 >> V_14 ;
V_15 = F_9 ( V_3 * sizeof( struct V_16 ) ) ;
for ( V_6 = 0 ; V_6 < V_3 ; ++ V_6 ) {
V_9 = F_10 ( V_2 , V_2 ) ;
F_11 ( L_2 , V_9 ,
V_2 >> 20 ) ;
V_15 [ V_6 ] . V_17 = V_9 ;
V_15 [ V_6 ] . V_18 = F_12 ( V_9 ) >> V_14 ;
V_15 [ V_6 ] . V_8 = V_8 ;
F_13 ( & V_15 [ V_6 ] . V_19 , & V_20 ) ;
F_14 ( & V_15 [ V_6 ] . V_21 , 0 ) ;
V_11 = F_15 ( V_15 [ V_6 ] . V_18 ) ;
for ( V_7 = 0 ; V_7 < V_8 ; ++ V_7 ) {
F_16 ( & V_11 -> V_22 ) ;
++ V_11 ;
}
}
}
struct V_16 * F_17 ( void )
{
struct V_16 * V_23 ;
V_23 = NULL ;
F_18 ( & V_24 ) ;
if ( ! F_19 ( & V_20 ) ) {
V_23 = F_20 ( & V_20 , struct V_16 , V_19 ) ;
F_21 ( & V_23 -> V_19 ) ;
F_16 ( & V_23 -> V_21 ) ;
}
F_22 ( & V_24 ) ;
return V_23 ;
}
void F_23 ( struct V_16 * V_23 )
{
if ( F_24 ( & V_23 -> V_21 ) ) {
F_18 ( & V_24 ) ;
F_13 ( & V_23 -> V_19 , & V_20 ) ;
F_22 ( & V_24 ) ;
}
}
