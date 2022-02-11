static void F_1 ( void )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < F_2 ( V_2 ) ; V_1 ++ ) {
if ( ! V_2 [ V_1 ] )
continue;
F_3 ( V_2 [ V_1 ] -> V_3 , V_2 [ V_1 ] -> V_4 ) ;
}
}
static void F_4 ( void )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < F_2 ( V_2 ) ; V_1 ++ ) {
if ( ! V_2 [ V_1 ] )
continue;
F_5 ( V_2 [ V_1 ] -> V_5 , V_2 [ V_1 ] -> V_6 ) ;
if ( V_2 [ V_1 ] -> V_7 )
F_6 ( V_2 [ V_1 ] -> V_7 ,
V_2 [ V_1 ] -> V_8 ) ;
}
}
static int F_7 ( struct V_9 * V_10 ,
unsigned long V_11 , void * V_12 )
{
static bool V_13 ;
static bool V_14 ;
struct V_15 * V_16 = V_12 ;
const char * V_17 ;
if ( V_11 != V_18 )
return V_19 ;
V_17 = F_8 ( V_16 ) ;
if ( ! V_13 && ! strcmp ( V_17 , V_20 ) ) {
F_1 () ;
V_13 = true ;
} else if ( ! V_14 && ! strcmp ( V_17 , V_21 ) ) {
F_4 () ;
V_14 = true ;
}
if ( V_13 && V_14 )
return V_22 ;
else
return V_19 ;
}
void F_9 ( struct V_23 * V_24 ,
struct V_23 * V_25 )
{
V_2 [ 0 ] = V_24 ;
V_2 [ 1 ] = V_25 ;
F_10 ( & V_26 , & V_10 ) ;
if ( ! F_11 ( L_1 ) )
F_12 ( V_27 , F_2 ( V_27 ) ) ;
}
