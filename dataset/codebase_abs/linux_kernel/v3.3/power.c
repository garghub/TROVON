void
F_1 (
void * V_1 ,
unsigned short V_2
)
{
T_1 V_3 = ( T_1 ) V_1 ;
T_2 V_4 = V_3 -> V_4 ;
unsigned short V_5 = V_4 -> V_6 | V_7 | V_8 ;
F_2 ( V_3 -> V_9 + V_10 , V_11 ) ;
if ( V_3 -> V_12 != V_13 ) {
F_2 ( V_3 -> V_9 + V_14 , V_5 ) ;
} else {
F_3 ( V_3 -> V_9 , V_4 -> V_15 ) ;
}
F_4 ( V_3 -> V_9 , V_16 , V_17 ) ;
F_4 ( V_3 -> V_9 , V_18 , V_19 ) ;
if ( V_2 >= 2 ) {
F_5 ( V_3 -> V_9 , V_20 , V_21 ) ;
F_4 ( V_3 -> V_9 , V_20 , V_22 ) ;
V_4 -> V_23 = V_2 ;
}
else {
F_4 ( V_3 -> V_9 , V_20 , V_21 ) ;
V_4 -> V_23 = 0 ;
}
F_4 ( V_3 -> V_9 , V_20 , V_24 ) ;
V_3 -> V_25 = true ;
if ( V_3 -> V_12 == V_13 ) {
}
else if ( V_3 -> V_12 == V_26 ) {
F_6 ( V_3 ) ;
}
V_3 -> V_27 = true ;
F_7 ( V_28 , V_29 L_1 ) ;
return;
}
void
F_8 (
void * V_1
)
{
T_1 V_3 = ( T_1 ) V_1 ;
F_9 ( V_3 -> V_9 ) ;
F_5 ( V_3 -> V_9 , V_16 , V_17 ) ;
F_5 ( V_3 -> V_9 , V_18 , V_19 ) ;
F_4 ( V_3 -> V_9 , V_20 , V_21 ) ;
V_3 -> V_25 = false ;
if ( V_3 -> V_12 == V_26 ) {
F_6 ( V_3 ) ;
}
V_3 -> V_27 = false ;
return;
}
bool
F_10 (
void * V_1 ,
bool V_30 ,
bool V_31
)
{
T_1 V_3 = ( T_1 ) V_1 ;
T_2 V_4 = V_3 -> V_4 ;
unsigned int V_32 ;
if ( F_11 ( V_3 -> V_9 , V_20 , V_33 ) )
return true ;
if ( V_4 -> V_34 != V_35 ) {
if ( V_4 -> V_36 )
return false ;
}
if ( V_3 -> V_37 )
return false ;
F_4 ( V_3 -> V_9 , V_20 , V_24 ) ;
for ( V_32 = 0 ; V_32 < V_38 ; V_32 ++ ) {
if ( V_3 -> V_39 [ V_32 ] != 0 )
return false ;
}
if ( V_30 &&
( ( V_3 -> V_40 & V_41 ) != 0 ) &&
( ( V_3 -> V_40 & V_42 ) != 0 ) ) {
return false ;
}
if ( V_4 -> V_34 != V_35 ) {
if ( V_31 &&
( V_4 -> V_23 == 0 || V_4 -> V_23 == 1 ) ) {
return false ;
}
}
F_4 ( V_3 -> V_9 , V_20 , V_43 ) ;
F_7 ( V_28 , V_29 L_2 ) ;
return true ;
}
void
F_12 (
void * V_1
)
{
T_1 V_3 = ( T_1 ) V_1 ;
T_2 V_4 = V_3 -> V_4 ;
T_3 V_44 = NULL ;
memset ( V_4 -> V_45 , 0 , sizeof( V_46 ) + V_47 ) ;
V_44 = ( T_3 ) V_4 -> V_45 ;
V_44 -> V_48 = ( V_49 ) ( ( unsigned char * ) V_44 + sizeof( V_46 ) ) ;
V_44 -> V_48 -> V_50 . V_51 = F_13 (
(
F_14 ( V_52 ) |
F_15 ( V_53 ) |
F_16 ( 0 )
) ) ;
V_44 -> V_48 -> V_50 . V_54 = V_4 -> V_6 | V_7 | V_8 ;
memcpy ( V_44 -> V_48 -> V_50 . V_55 , V_4 -> V_56 , V_57 ) ;
memcpy ( V_44 -> V_48 -> V_50 . V_58 , V_4 -> V_59 , V_57 ) ;
V_44 -> V_60 = V_47 ;
V_44 -> V_61 = 0 ;
if ( F_17 ( V_3 , V_44 ) != V_62 ) {
F_7 ( V_28 , V_29 L_3 ) ;
}
else {
} ;
return;
}
bool
F_6 (
void * V_1
)
{
T_1 V_3 = ( T_1 ) V_1 ;
T_3 V_44 = NULL ;
T_2 V_4 = V_3 -> V_4 ;
unsigned int V_32 ;
if ( V_3 -> V_63 == false ) {
return false ;
}
#ifdef F_18
if ( ( V_3 -> V_25 == false ) &&
( V_3 -> V_64 == false ) ) {
return false ;
}
#else
if ( V_3 -> V_25 == false ) {
return false ;
}
#endif
if ( V_3 -> V_25 ) {
for ( V_32 = 0 ; V_32 < V_38 ; V_32 ++ ) {
if ( V_3 -> V_39 [ V_32 ] != 0 )
return false ;
}
}
memset ( V_4 -> V_45 , 0 , sizeof( V_46 ) + V_65 ) ;
V_44 = ( T_3 ) V_4 -> V_45 ;
V_44 -> V_48 = ( V_49 ) ( ( unsigned char * ) V_44 + sizeof( V_46 ) ) ;
if ( V_3 -> V_25 ) {
V_44 -> V_48 -> V_66 . V_51 = F_13 (
(
F_14 ( V_67 ) |
F_15 ( V_68 ) |
F_16 ( 1 )
) ) ;
}
else {
V_44 -> V_48 -> V_66 . V_51 = F_13 (
(
F_14 ( V_67 ) |
F_15 ( V_68 ) |
F_16 ( 0 )
) ) ;
}
if( V_4 -> V_34 != V_35 ) {
V_44 -> V_48 -> V_66 . V_51 |= F_13 ( ( unsigned short ) F_19 ( 1 ) ) ;
}
memcpy ( V_44 -> V_48 -> V_66 . V_55 , V_4 -> V_56 , V_57 ) ;
memcpy ( V_44 -> V_48 -> V_66 . V_58 , V_4 -> V_59 , V_57 ) ;
memcpy ( V_44 -> V_48 -> V_66 . V_69 , V_4 -> V_56 , V_70 ) ;
V_44 -> V_60 = V_71 ;
V_44 -> V_61 = 0 ;
if ( F_17 ( V_3 , V_44 ) != V_62 ) {
F_7 ( V_28 , V_29 L_4 ) ;
return false ;
}
else {
}
return true ;
}
bool
F_20 (
void * V_1
)
{
T_1 V_3 = ( T_1 ) V_1 ;
T_2 V_4 = V_3 -> V_4 ;
bool V_72 = false ;
if ( V_4 -> V_2 >= 2 ) {
if ( V_4 -> V_23 == 0 ) {
V_4 -> V_23 = V_4 -> V_2 ;
}
V_4 -> V_23 -- ;
if ( V_4 -> V_23 == 1 ) {
F_4 ( V_3 -> V_9 , V_20 , V_22 ) ;
V_72 = true ;
}
}
return V_72 ;
}
