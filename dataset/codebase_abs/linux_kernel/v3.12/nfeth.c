static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 ;
V_5 = F_3 ( V_6 + V_7 , V_4 -> V_8 ) ;
F_4 ( V_2 , L_1 , V_9 , V_5 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_7 ( V_2 ) ;
F_3 ( V_6 + V_10 , V_4 -> V_8 ) ;
return 0 ;
}
static inline void F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned short V_11 ;
struct V_12 * V_13 ;
V_11 = F_3 ( V_6 + V_14 , V_4 -> V_8 ) ;
F_4 ( V_2 , L_2 , V_9 , V_11 ) ;
if ( ! V_11 ) {
F_4 ( V_2 , L_3 , V_9 ) ;
V_2 -> V_15 . V_16 ++ ;
return;
}
V_13 = F_9 ( V_11 + 2 ) ;
if ( ! V_13 ) {
F_4 ( V_2 , L_4 ,
V_9 ) ;
V_2 -> V_15 . V_17 ++ ;
return;
}
V_13 -> V_2 = V_2 ;
F_10 ( V_13 , 2 ) ;
F_11 ( V_13 , V_11 ) ;
F_3 ( V_6 + V_18 , V_4 -> V_8 , F_12 ( V_13 -> V_19 ) ,
V_11 ) ;
V_13 -> V_20 = F_13 ( V_13 , V_2 ) ;
F_14 ( V_13 ) ;
V_2 -> V_21 = V_22 ;
V_2 -> V_15 . V_23 ++ ;
V_2 -> V_15 . V_24 += V_11 ;
return;
}
static T_1 F_15 ( int V_25 , void * V_26 )
{
int V_27 , V_28 , V_29 ;
V_29 = F_3 ( V_6 + V_30 , 0 ) ;
for ( V_27 = 0 , V_28 = 1 ; V_27 < V_31 ; V_28 <<= 1 , V_27 ++ ) {
if ( V_29 & V_28 && V_32 [ V_27 ] ) {
F_8 ( V_32 [ V_27 ] ) ;
F_3 ( V_6 + V_30 , V_28 ) ;
}
}
return V_33 ;
}
static int F_16 ( struct V_12 * V_13 , struct V_1 * V_2 )
{
unsigned int V_34 ;
char * V_19 , V_35 [ V_36 ] ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_19 = V_13 -> V_19 ;
V_34 = V_13 -> V_34 ;
if ( V_34 < V_36 ) {
memset ( V_35 , 0 , V_36 ) ;
memcpy ( V_35 , V_19 , V_34 ) ;
V_19 = V_35 ;
V_34 = V_36 ;
}
F_4 ( V_2 , L_5 , V_9 , V_34 ) ;
F_3 ( V_6 + V_37 , V_4 -> V_8 , F_12 ( V_19 ) ,
V_34 ) ;
V_2 -> V_15 . V_38 ++ ;
V_2 -> V_15 . V_39 += V_34 ;
F_17 ( V_13 ) ;
return 0 ;
}
static void F_18 ( struct V_1 * V_2 )
{
V_2 -> V_15 . V_40 ++ ;
F_19 ( V_2 ) ;
}
static struct V_1 * T_2 F_20 ( int V_41 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
char V_42 [ V_43 ] , V_44 [ 32 ] , V_45 [ 32 ] ;
int V_46 ;
if ( ! F_3 ( V_6 + V_47 , V_41 , F_12 ( V_42 ) ,
V_43 ) )
return NULL ;
V_2 = F_21 ( sizeof( struct V_3 ) ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_25 = V_48 ;
V_2 -> V_49 = & V_50 ;
memcpy ( V_2 -> V_51 , V_42 , V_43 ) ;
V_4 = F_2 ( V_2 ) ;
V_4 -> V_8 = V_41 ;
V_46 = F_22 ( V_2 ) ;
if ( V_46 ) {
F_23 ( V_2 ) ;
return NULL ;
}
F_3 ( V_6 + V_52 , V_41 ,
F_12 ( V_44 ) , sizeof( V_44 ) ) ;
F_3 ( V_6 + V_53 , V_41 ,
F_12 ( V_45 ) , sizeof( V_45 ) ) ;
F_24 ( V_2 , V_54 L_6 , V_44 ,
V_45 , V_42 ) ;
return V_2 ;
}
static int T_2 F_25 ( void )
{
long V_55 ;
int error , V_27 ;
V_6 = F_26 ( L_7 ) ;
if ( ! V_6 )
return - V_56 ;
V_55 = F_3 ( V_6 + V_57 ) ;
F_27 ( L_8 , V_55 ) ;
V_48 = F_3 ( V_6 + V_58 ) ;
error = F_28 ( V_48 , F_15 , V_59 ,
L_9 , F_15 ) ;
if ( error ) {
F_29 ( L_10 , V_48 , error ) ;
return error ;
}
for ( V_27 = 0 ; V_27 < V_31 ; V_27 ++ )
V_32 [ V_27 ] = F_20 ( V_27 ) ;
return 0 ;
}
static void T_3 F_30 ( void )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < V_31 ; V_27 ++ ) {
if ( V_32 [ V_27 ] ) {
F_31 ( V_32 [ 0 ] ) ;
F_23 ( V_32 [ 0 ] ) ;
}
}
F_32 ( V_48 , F_15 ) ;
}
