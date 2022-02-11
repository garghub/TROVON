int F_1 ( void )
{
struct V_1 * V_2 ;
V_2 = F_2 ( NULL , L_1 , L_2 ) ;
if ( V_2 ) {
F_3 ( V_2 ) ;
return 0 ;
}
return - V_3 ;
}
int F_4 ( void )
{
struct V_1 * V_4 ;
struct V_5 V_6 ;
unsigned int V_7 ;
V_4 = F_2 ( NULL , L_1 , L_2 ) ;
if ( V_4 == 0 )
return - V_8 ;
if ( F_5 ( V_4 , 0 , & V_6 ) ) {
F_3 ( V_4 ) ;
return - V_8 ;
}
V_9 = F_6 ( V_6 . V_10 , sizeof( struct V_11 ) ) ;
F_7 ( & V_9 -> V_12 . V_6 , 0 ) ;
F_7 ( & V_9 -> V_13 . V_6 , 0 ) ;
F_7 ( & V_9 -> error . V_6 , 0 ) ;
F_7 ( & V_9 -> V_14 . V_6 , 0xff ) ;
F_7 ( & V_9 -> V_15 . V_6 , 0xff ) ;
F_7 ( & V_9 -> V_16 . V_6 , V_17 ) ;
V_7 = F_8 ( V_4 , 0 ) ;
F_3 ( V_4 ) ;
if ( F_9 ( V_7 , V_18 , 0 , L_3 , ( void * ) 0 ) ) {
F_10 ( V_19 L_4 , V_7 ) ;
return - V_20 ;
}
F_7 ( & V_9 -> V_21 . V_6 , V_22 | V_23 ) ;
F_10 ( L_5 ) ;
return 0 ;
}
static int F_11 ( int V_24 )
{
unsigned long V_25 ;
F_12 ( & V_26 , V_25 ) ;
F_7 ( & V_9 -> V_14 . V_6 , V_24 >> 8 ) ;
F_7 ( & V_9 -> V_15 . V_6 , V_24 ) ;
F_7 ( & V_9 -> V_16 . V_6 , V_24 ? V_17 : 0 ) ;
F_13 ( & V_26 , V_25 ) ;
return 0 ;
}
static int F_14 ( void )
{
unsigned long V_25 ;
int V_27 = 1000000 ;
F_12 ( & V_26 , V_25 ) ;
F_7 ( & V_9 -> V_12 . V_6 , F_15 ( & V_9 -> V_12 . V_6 ) | V_28 ) ;
while ( ( F_15 ( & V_9 -> V_12 . V_6 ) & V_28 ) != 0 ) {
if ( -- V_27 == 0 ) {
F_7 ( & V_9 -> V_12 . V_6 , F_15 ( & V_9 -> V_12 . V_6 ) & ~ V_28 ) ;
F_13 ( & V_26 , V_25 ) ;
return - 1 ;
}
}
F_13 ( & V_26 , V_25 ) ;
return 0 ;
}
static int F_16 ( struct V_29 * V_30 , int V_31 )
{
unsigned long V_25 ;
int V_32 ;
if ( V_30 -> V_33 [ 0 ] != V_34 )
return - V_35 ;
for ( V_32 = 0 ; V_32 < V_30 -> V_36 - 1 ; ++ V_32 )
V_30 -> V_33 [ V_32 ] = V_30 -> V_33 [ V_32 + 1 ] ;
-- V_30 -> V_36 ;
V_30 -> V_37 = NULL ;
V_30 -> V_38 = 0 ;
V_30 -> V_39 = 0 ;
V_30 -> V_40 = 0 ;
F_12 ( & V_26 , V_25 ) ;
if ( V_41 != 0 ) {
V_42 -> V_37 = V_30 ;
V_42 = V_30 ;
} else {
V_41 = V_42 = V_30 ;
F_7 ( & V_9 -> V_12 . V_6 , F_15 ( & V_9 -> V_12 . V_6 ) | V_43 ) ;
}
F_13 ( & V_26 , V_25 ) ;
if ( V_31 ) {
while ( ! V_30 -> V_39 )
F_17 () ;
}
return 0 ;
}
static T_1 V_18 ( int V_7 , void * V_44 )
{
int V_32 , V_45 , V_46 ;
struct V_29 * V_30 = NULL ;
unsigned char V_47 [ 16 ] ;
int V_48 = 0 ;
int V_39 = 0 ;
int V_16 = 0 ;
int V_49 = 0 ;
F_18 ( & V_26 ) ;
if ( F_15 ( & V_9 -> V_13 . V_6 ) & V_23 ) {
V_49 = 1 ;
if ( ( V_30 = V_41 ) != 0 ) {
for ( V_32 = 0 ; V_32 < V_30 -> V_36 ; ++ V_32 )
F_7 ( & V_9 -> V_33 [ V_32 ] . V_6 , V_30 -> V_33 [ V_32 ] ) ;
F_7 ( & V_9 -> V_50 . V_6 , V_30 -> V_36 & V_51 ) ;
V_30 -> V_38 = 1 ;
if ( V_30 -> V_52 ) {
F_7 ( & V_9 -> V_12 . V_6 , V_53 + V_54 ) ;
} else {
F_7 ( & V_9 -> V_12 . V_6 , V_53 ) ;
V_41 = V_30 -> V_37 ;
V_39 = 1 ;
if ( V_41 )
F_7 ( & V_9 -> V_12 . V_6 , F_15 ( & V_9 -> V_12 . V_6 ) | V_43 ) ;
}
}
F_7 ( & V_9 -> V_13 . V_6 , 0 ) ;
}
if ( F_15 ( & V_9 -> V_13 . V_6 ) & V_22 ) {
V_49 = 1 ;
V_46 = F_15 ( & V_9 -> error . V_6 ) ;
if ( V_41 && V_41 -> V_38 ) {
V_30 = V_41 ;
if ( V_46 == 0 ) {
V_30 -> V_40 = F_15 ( & V_9 -> V_50 . V_6 ) & V_51 ;
for ( V_32 = 0 ; V_32 < V_30 -> V_40 ; ++ V_32 )
V_30 -> V_55 [ V_32 ] = F_15 ( & V_9 -> V_33 [ V_32 ] . V_6 ) ;
}
V_41 = V_30 -> V_37 ;
V_39 = 1 ;
if ( V_41 )
F_7 ( & V_9 -> V_12 . V_6 , F_15 ( & V_9 -> V_12 . V_6 ) | V_43 ) ;
} else if ( V_46 == 0 ) {
V_45 = F_15 ( & V_9 -> V_50 . V_6 ) & V_51 ;
for ( V_32 = 0 ; V_32 < V_45 ; ++ V_32 )
V_47 [ V_32 ] = F_15 ( & V_9 -> V_33 [ V_32 ] . V_6 ) ;
V_48 = V_45 ;
V_16 = ( F_15 ( & V_9 -> V_50 . V_6 ) & V_56 ) != 0 ;
}
F_7 ( & V_9 -> error . V_6 , 0 ) ;
F_7 ( & V_9 -> V_13 . V_6 , 0 ) ;
}
F_19 ( & V_26 ) ;
if ( V_39 && V_30 ) {
void (* F_20)( struct V_29 * ) = V_30 -> F_20 ;
F_21 () ;
V_30 -> V_39 = 1 ;
if ( F_20 )
(* F_20)( V_30 ) ;
}
if ( V_48 )
F_22 ( V_47 , V_48 , V_16 ) ;
return F_23 ( V_49 ) ;
}
static void F_17 ( void )
{
unsigned long V_25 ;
F_24 ( V_25 ) ;
if ( F_15 ( & V_9 -> V_13 . V_6 ) != 0 )
V_18 ( 0 , NULL ) ;
F_25 ( V_25 ) ;
}
