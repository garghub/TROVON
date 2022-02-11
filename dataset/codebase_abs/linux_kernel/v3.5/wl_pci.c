int F_1 ( void )
{
int V_1 ;
F_2 ( L_1 ) ;
F_3 ( V_2 ) ;
F_4 ( V_2 , L_2 ) ;
V_1 = F_5 ( & V_3 ) ;
F_6 ( V_2 ) ;
return 0 ;
}
void F_7 ( void )
{
F_2 ( L_3 ) ;
F_3 ( V_2 ) ;
F_4 ( V_2 , L_4 ) ;
F_8 ( & V_3 ) ;
F_6 ( V_2 ) ;
return;
}
int F_9 ( struct V_4 * V_5 )
{
int V_1 = FALSE ;
F_2 ( L_5 ) ;
F_3 ( V_2 ) ;
F_4 ( V_2 , L_6 ) ;
if( V_5 == NULL ) {
F_10 ( V_2 , L_7 ) ;
} else if( V_5 -> V_6 == NULL ) {
F_10 ( V_2 , L_8 ) ;
} else if( F_11 ( V_5 ) ) {
V_1 = TRUE ;
} else {
F_4 ( V_2 , L_9 ) ;
}
F_6 ( V_2 ) ;
return V_1 ;
}
int F_12 ( struct V_4 * V_5 )
{
int V_1 = 0 ;
int V_7 = V_8 ;
F_2 ( L_10 ) ;
F_3 ( V_2 ) ;
F_4 ( V_2 , L_11 ) ;
V_7 = F_13 ( V_5 ) ;
if( V_7 != V_8 ) {
V_1 = - V_9 ;
}
F_6 ( V_2 ) ;
return V_1 ;
}
int F_14 ( struct V_4 * V_5 )
{
F_2 ( L_12 ) ;
F_3 ( V_2 ) ;
F_4 ( V_2 , L_13 ) ;
F_4 ( V_2 , L_14 , V_5 -> V_10 ) ;
F_15 ( V_5 ) ;
F_6 ( V_2 ) ;
return 0 ;
}
int F_16 ( struct V_4 * V_5 )
{
return TRUE ;
}
int T_1 F_17 ( struct V_11 * V_12 ,
const struct V_13 * V_14 )
{
int V_1 ;
F_2 ( L_15 ) ;
F_3 ( V_2 ) ;
F_18 ( L_16 , V_15 ) ;
V_1 = F_19 ( V_12 ) ;
F_6 ( V_2 ) ;
return V_1 ;
}
void T_2 F_20 ( struct V_11 * V_12 )
{
struct V_4 * V_5 = NULL ;
F_2 ( L_17 ) ;
F_3 ( V_2 ) ;
if( V_12 == NULL ) {
F_10 ( V_2 , L_18 ) ;
return;
}
V_5 = F_21 ( V_12 ) ;
if( V_5 == NULL ) {
F_10 ( V_2 , L_19 ) ;
return;
}
F_22 ( V_5 ) ;
F_23 ( V_5 -> V_16 , V_5 ) ;
#ifdef F_24
F_25 ( V_12 , V_5 -> V_6 ) ;
#endif
F_26 ( V_5 ) ;
F_6 ( V_2 ) ;
return;
}
int F_19 ( struct V_11 * V_12 )
{
int V_1 = 0 ;
struct V_4 * V_5 = NULL ;
struct V_17 * V_18 = NULL ;
F_2 ( L_20 ) ;
F_3 ( V_2 ) ;
if( V_12 == NULL ) {
F_10 ( V_2 , L_18 ) ;
return - V_9 ;
}
V_1 = F_27 ( V_12 ) ;
if( V_1 != 0 ) {
F_10 ( V_2 , L_21 ) ;
F_6 ( V_2 ) ;
return V_1 ;
}
F_4 ( V_2 , L_22 ) ;
V_5 = F_28 ( ) ;
if( V_5 == NULL ) {
F_10 ( V_2 , L_23 ) ;
F_6 ( V_2 ) ;
return - V_19 ;
}
if( V_5 -> V_6 == NULL ) {
F_10 ( V_2 , L_24 ) ;
F_26 ( V_5 ) ;
F_6 ( V_2 ) ;
return - V_19 ;
}
#ifdef F_24
if( F_29 ( V_12 , V_5 -> V_6 ) < 0 ) {
F_10 ( V_2 , L_25 ) ;
F_26 ( V_5 ) ;
F_6 ( V_2 ) ;
return - V_19 ;
}
#endif
F_30 ( V_12 , V_5 ) ;
V_5 -> V_16 = V_12 -> V_16 ;
F_31 ( V_5 ) ;
F_4 ( V_2 , L_26 , V_12 -> V_20 [ 0 ] . V_21 ) ;
V_5 -> V_22 = V_12 -> V_20 [ 0 ] . V_21 ;
if( ! F_9 ( V_5 ) ) {
F_10 ( V_2 , L_27 ) ;
F_26 ( V_5 ) ;
F_6 ( V_2 ) ;
return - V_23 ;
}
F_4 ( V_2 , L_28 ) ;
V_1 = F_32 ( V_5 -> V_16 , V_24 , V_25 , V_5 -> V_10 , V_5 ) ;
if( V_1 ) {
F_33 ( V_2 , L_29 ) ;
F_22 ( V_5 ) ;
F_26 ( V_5 ) ;
F_6 ( V_2 ) ;
return V_1 ;
}
V_18 = V_5 -> V_6 ;
if( V_18 -> V_26 . V_27 == V_28 ||
V_18 -> V_26 . V_27 == V_29 ) {
F_4 ( V_2 , L_30 ) ;
F_34 ( V_12 ) ;
}
F_35 ( V_12 ) ;
F_6 ( V_2 ) ;
return 0 ;
}
void F_34 ( struct V_11 * V_12 )
{
T_3 V_30 ;
T_3 V_31 ;
T_3 V_32 ;
void * V_33 = NULL ;
F_2 ( L_31 ) ;
F_3 ( V_2 ) ;
V_30 = 0xdeadbeef ;
V_31 = 0xdeadbeef ;
F_36 ( V_12 , V_34 , & V_30 ) ;
V_31 = V_30 & V_35 ;
V_33 = F_37 ( V_31 , 0x200 ) ;
#ifdef F_38
#define F_39 0x07F4
#else
#define F_39 0x01F4
#endif
#define F_40 0x8000
V_32 = * ( T_3 * ) ( V_33 + F_39 ) ;
V_32 |= F_40 ;
* ( T_3 * ) ( V_33 + F_39 ) = V_32 ;
F_41 ( V_33 ) ;
F_6 ( V_2 ) ;
return;
}
int F_29 ( struct V_11 * V_12 , struct V_17 * V_18 )
{
int V_36 ;
int V_37 = 0 ;
F_2 ( L_32 ) ;
F_3 ( V_2 ) ;
return V_37 ;
}
int F_25 ( struct V_11 * V_12 , struct V_17 * V_18 )
{
int V_36 ;
int V_37 = 0 ;
F_2 ( L_33 ) ;
F_3 ( V_2 ) ;
for( V_36 = 0 ; V_36 < V_38 ; V_36 ++ ) {
if( V_18 -> V_39 . V_40 [ V_36 ] ) {
V_37 = F_42 ( V_12 , V_18 , & V_18 -> V_39 . V_40 [ V_36 ] ) ;
if( V_37 != 0 ) {
F_33 ( V_2 , L_34 ) ;
}
}
}
V_18 -> V_39 . V_41 = 0 ;
if( V_18 -> V_39 . V_42 ) {
V_37 = F_43 ( V_12 , V_18 , & V_18 -> V_39 . V_42 ) ;
if( V_37 != 0 ) {
F_33 ( V_2 , L_35 ) ;
}
}
for( V_36 = 0 ; V_36 < V_43 ; V_36 ++ ) {
if( V_18 -> V_39 . V_44 [ V_36 ] ) {
V_37 = F_44 ( V_12 , V_18 , & V_18 -> V_39 . V_44 [ V_36 ] ) ;
if( V_37 != 0 ) {
F_33 ( V_2 , L_36 ) ;
}
}
}
V_18 -> V_39 . V_45 = 0 ;
if( V_18 -> V_39 . V_46 ) {
V_37 = F_43 ( V_12 , V_18 , & V_18 -> V_39 . V_46 ) ;
if( V_37 != 0 ) {
F_33 ( V_2 , L_37 ) ;
}
}
F_6 ( V_2 ) ;
return V_37 ;
}
int F_45 ( struct V_11 * V_12 , struct V_17 * V_18 ,
T_4 * * V_47 )
{
}
int F_44 ( struct V_11 * V_12 , struct V_17 * V_18 ,
T_4 * * V_47 )
{
int V_37 = 0 ;
if( * V_47 == NULL ) {
F_18 ( L_38 ) ;
V_37 = - V_48 ;
}
if( V_37 == 0 && ( * V_47 ) -> V_49 ) {
V_37 = F_46 ( V_12 , V_18 , & ( * V_47 ) -> V_49 ) ;
}
if( V_37 == 0 ) {
V_37 = F_46 ( V_12 , V_18 , V_47 ) ;
}
return V_37 ;
}
int F_47 ( struct V_11 * V_12 , struct V_17 * V_18 ,
T_4 * * V_47 )
{
int V_37 = 0 ;
T_4 * V_50 ;
return V_37 ;
}
int F_42 ( struct V_11 * V_12 , struct V_17 * V_18 ,
T_4 * * V_47 )
{
int V_37 = 0 ;
T_4 * V_50 ;
if( * V_47 == NULL ) {
V_37 = - V_48 ;
}
if( V_37 == 0 ) {
V_50 = ( * V_47 ) -> V_49 ;
if( V_50 != NULL ) {
V_50 -> V_51 = NULL ;
V_50 -> V_52 = 0 ;
V_37 = F_43 ( V_12 , V_18 , & V_50 ) ;
}
}
if( V_37 == 0 ) {
F_48 ( * V_47 , V_53 ) ;
V_37 = F_46 ( V_12 , V_18 , V_47 ) ;
}
return V_37 ;
}
int F_49 ( struct V_11 * V_12 , struct V_17 * V_18 ,
T_4 * * V_47 , int V_54 )
{
int V_37 = 0 ;
return V_37 ;
}
int F_46 ( struct V_11 * V_12 , struct V_17 * V_18 ,
T_4 * * V_47 )
{
int V_37 = 0 ;
if( V_47 == NULL ) {
V_37 = - V_48 ;
}
if( V_37 == 0 && * V_47 == NULL ) {
V_37 = - V_48 ;
}
if( V_37 == 0 ) {
V_37 = F_50 ( V_12 , V_18 , * V_47 ) ;
if( V_37 == 0 ) {
V_37 = F_43 ( V_12 , V_18 , V_47 ) ;
}
}
return V_37 ;
}
int F_51 ( struct V_11 * V_12 , struct V_17 * V_18 ,
T_4 * * V_47 )
{
}
int F_43 ( struct V_11 * V_12 , struct V_17 * V_18 ,
T_4 * * V_47 )
{
int V_37 = 0 ;
if( * V_47 == NULL ) {
V_37 = - V_48 ;
}
if( V_37 == 0 ) {
F_52 ( V_12 , sizeof( T_4 ) , * V_47 ,
( * V_47 ) -> V_55 ) ;
}
* V_47 = NULL ;
return V_37 ;
}
int F_53 ( struct V_11 * V_12 , struct V_17 * V_18 ,
T_4 * V_47 , int V_54 )
{
int V_37 = 0 ;
T_5 V_56 ;
return V_37 ;
}
int F_50 ( struct V_11 * V_12 , struct V_17 * V_18 ,
T_4 * V_47 )
{
int V_37 = 0 ;
if( V_47 == NULL ) {
V_37 = - V_48 ;
}
if( V_37 == 0 && V_47 -> V_51 == NULL ) {
V_37 = - V_48 ;
}
if( V_37 == 0 ) {
F_52 ( V_12 , F_54 ( V_47 ) , V_47 -> V_51 ,
V_47 -> V_52 ) ;
V_47 -> V_51 = 0 ;
V_47 -> V_52 = 0 ;
F_48 ( V_47 , 0 ) ;
}
return V_37 ;
}
void F_55 ( struct V_17 * V_18 )
{
int V_36 ;
F_2 ( L_39 ) ;
F_3 ( V_2 ) ;
if( V_18 -> V_39 . V_46 ) {
F_18 ( L_40 , V_18 -> V_39 . V_46 ) ;
F_56 ( & V_18 -> V_26 , V_18 -> V_39 . V_46 , 0 ) ;
V_18 -> V_39 . V_46 = NULL ;
F_18 ( L_40 , V_18 -> V_39 . V_46 ) ;
}
if( V_18 -> V_39 . V_42 ) {
F_18 ( L_41 , V_18 -> V_39 . V_42 ) ;
F_57 ( & V_18 -> V_26 , V_18 -> V_39 . V_42 ) ;
V_18 -> V_39 . V_42 = NULL ;
F_18 ( L_41 , V_18 -> V_39 . V_42 ) ;
}
for( V_36 = 0 ; V_36 < V_38 ; V_36 ++ ) {
F_18 ( L_42 , V_36 , V_18 -> V_39 . V_40 [ V_36 ] ) ;
F_57 ( & V_18 -> V_26 , V_18 -> V_39 . V_40 [ V_36 ] ) ;
V_18 -> V_39 . V_40 [ V_36 ] = NULL ;
F_18 ( L_42 , V_36 , V_18 -> V_39 . V_40 [ V_36 ] ) ;
}
F_6 ( V_2 ) ;
return;
}
void F_58 ( struct V_17 * V_18 )
{
int V_36 ;
F_2 ( L_43 ) ;
F_3 ( V_2 ) ;
F_59 ( V_18 ) ;
for( V_36 = 0 ; V_36 < V_38 ; V_36 ++ ) {
F_18 ( L_44 , V_36 , V_18 -> V_39 . V_40 [ V_36 ] ) ;
}
F_60 ( V_18 ) ;
for( V_36 = 0 ; V_36 < V_43 ; V_36 ++ ) {
F_18 ( L_45 , V_36 , V_18 -> V_39 . V_44 [ V_36 ] ) ;
}
F_6 ( V_2 ) ;
return;
}
void F_59 ( struct V_17 * V_18 )
{
int V_36 ;
T_4 * V_50 ;
F_2 ( L_46 ) ;
F_3 ( V_2 ) ;
while ( ( V_50 = F_61 ( & V_18 -> V_26 ) ) != NULL ) {
if( V_50 && V_50 -> V_51 == NULL ) {
V_18 -> V_39 . V_42 = V_50 ;
F_18 ( L_47 , V_50 ) ;
continue;
}
for( V_36 = 0 ; V_36 < V_38 ; V_36 ++ ) {
if( V_18 -> V_39 . V_40 [ V_36 ] == NULL ) {
break;
}
}
V_18 -> V_39 . V_40 [ V_36 ] = V_50 ;
V_18 -> V_39 . V_41 ++ ;
F_18 ( L_44 , V_36 , V_18 -> V_39 . V_40 [ V_36 ] ) ;
}
F_6 ( V_2 ) ;
}
T_4 * F_62 ( struct V_17 * V_18 )
{
int V_36 ;
T_4 * V_47 = NULL ;
for( V_36 = 0 ; V_36 < V_43 ; V_36 ++ ) {
if( V_18 -> V_39 . V_44 [ V_36 ] ) {
break;
}
}
if( V_36 != V_43 ) {
V_47 = V_18 -> V_39 . V_44 [ V_36 ] ;
V_18 -> V_39 . V_44 [ V_36 ] = NULL ;
V_18 -> V_39 . V_45 -- ;
memset ( V_47 -> V_51 , 0 , V_57 ) ;
}
return V_47 ;
}
void F_63 ( struct V_17 * V_18 , T_4 * V_47 )
{
int V_36 ;
for( V_36 = 0 ; V_36 < V_43 ; V_36 ++ ) {
if( V_18 -> V_39 . V_44 [ V_36 ] == NULL ) {
break;
}
}
if( V_36 != V_43 ) {
V_18 -> V_39 . V_44 [ V_36 ] = V_47 ;
V_18 -> V_39 . V_45 ++ ;
}
}
void F_60 ( struct V_17 * V_18 )
{
int V_36 ;
T_4 * V_50 ;
F_2 ( L_48 ) ;
F_3 ( V_2 ) ;
while ( ( V_50 = F_64 ( & V_18 -> V_26 ) ) != NULL ) {
if( V_50 != NULL && V_50 -> V_51 == NULL ) {
V_18 -> V_39 . V_46 = V_50 ;
F_18 ( L_47 , V_50 ) ;
continue;
}
for( V_36 = 0 ; V_36 < V_43 ; V_36 ++ ) {
if( V_18 -> V_39 . V_44 [ V_36 ] == NULL ) {
break;
}
}
V_18 -> V_39 . V_44 [ V_36 ] = V_50 ;
V_18 -> V_39 . V_45 ++ ;
F_18 ( L_45 , V_36 , V_18 -> V_39 . V_44 [ V_36 ] ) ;
}
if( V_18 -> V_58 == FALSE ) {
F_65 ( V_18 -> V_5 ) ;
F_66 ( V_18 ) ;
V_18 -> V_58 = TRUE ;
}
F_6 ( V_2 ) ;
return;
}
