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
V_2 -> V_15 . V_21 ++ ;
V_2 -> V_15 . V_22 += V_11 ;
return;
}
static T_1 F_15 ( int V_23 , void * V_24 )
{
int V_25 , V_26 , V_27 ;
V_27 = F_3 ( V_6 + V_28 , 0 ) ;
for ( V_25 = 0 , V_26 = 1 ; V_25 < V_29 ; V_26 <<= 1 , V_25 ++ ) {
if ( V_27 & V_26 && V_30 [ V_25 ] ) {
F_8 ( V_30 [ V_25 ] ) ;
F_3 ( V_6 + V_28 , V_26 ) ;
}
}
return V_31 ;
}
static int F_16 ( struct V_12 * V_13 , struct V_1 * V_2 )
{
unsigned int V_32 ;
char * V_19 , V_33 [ V_34 ] ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_19 = V_13 -> V_19 ;
V_32 = V_13 -> V_32 ;
if ( V_32 < V_34 ) {
memset ( V_33 , 0 , V_34 ) ;
memcpy ( V_33 , V_19 , V_32 ) ;
V_19 = V_33 ;
V_32 = V_34 ;
}
F_4 ( V_2 , L_5 , V_9 , V_32 ) ;
F_3 ( V_6 + V_35 , V_4 -> V_8 , F_12 ( V_19 ) ,
V_32 ) ;
V_2 -> V_15 . V_36 ++ ;
V_2 -> V_15 . V_37 += V_32 ;
F_17 ( V_13 ) ;
return 0 ;
}
static void F_18 ( struct V_1 * V_2 )
{
V_2 -> V_15 . V_38 ++ ;
F_19 ( V_2 ) ;
}
static struct V_1 * T_2 F_20 ( int V_39 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
char V_40 [ V_41 ] , V_42 [ 32 ] , V_43 [ 32 ] ;
int V_44 ;
if ( ! F_3 ( V_6 + V_45 , V_39 , F_12 ( V_40 ) ,
V_41 ) )
return NULL ;
V_2 = F_21 ( sizeof( struct V_3 ) ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_23 = V_46 ;
V_2 -> V_47 = & V_48 ;
memcpy ( V_2 -> V_49 , V_40 , V_41 ) ;
V_4 = F_2 ( V_2 ) ;
V_4 -> V_8 = V_39 ;
V_44 = F_22 ( V_2 ) ;
if ( V_44 ) {
F_23 ( V_2 ) ;
return NULL ;
}
F_3 ( V_6 + V_50 , V_39 ,
F_12 ( V_42 ) , sizeof( V_42 ) ) ;
F_3 ( V_6 + V_51 , V_39 ,
F_12 ( V_43 ) , sizeof( V_43 ) ) ;
F_24 ( V_2 , V_52 L_6 , V_42 ,
V_43 , V_40 ) ;
return V_2 ;
}
static int T_2 F_25 ( void )
{
long V_53 ;
int error , V_25 ;
V_6 = F_26 ( L_7 ) ;
if ( ! V_6 )
return - V_54 ;
V_53 = F_3 ( V_6 + V_55 ) ;
F_27 ( L_8 , V_53 ) ;
V_46 = F_3 ( V_6 + V_56 ) ;
error = F_28 ( V_46 , F_15 , V_57 ,
L_9 , F_15 ) ;
if ( error ) {
F_29 ( L_10 , V_46 , error ) ;
return error ;
}
for ( V_25 = 0 ; V_25 < V_29 ; V_25 ++ )
V_30 [ V_25 ] = F_20 ( V_25 ) ;
return 0 ;
}
static void T_3 F_30 ( void )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < V_29 ; V_25 ++ ) {
if ( V_30 [ V_25 ] ) {
F_31 ( V_30 [ 0 ] ) ;
F_23 ( V_30 [ 0 ] ) ;
}
}
F_32 ( V_46 , F_15 ) ;
}
