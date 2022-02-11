struct V_1 * F_1 ( struct V_2 * V_2 )
{
struct V_1 * V_1 ;
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_7 * V_8 = & ( V_2 -> V_9 ) ;
V_1 = F_2 ( V_8 ) ;
if ( V_1 == NULL ) {
F_3 ( L_1 , V_10 ) ;
goto exit;
}
V_4 = F_4 ( V_8 ) ;
if ( V_4 == NULL ) {
F_3 ( L_2 , V_10 ) ;
F_5 ( V_8 , V_1 ) ;
V_1 = NULL ;
goto exit;
}
V_1 -> V_11 = V_12 ;
V_1 -> V_13 = V_4 ;
V_1 -> V_14 = V_4 -> V_15 ;
V_4 -> V_16 = V_1 ;
V_6 = & V_1 -> V_17 ;
F_6 ( V_2 , V_6 ) ;
V_6 -> V_18 = 0x10 ;
V_6 -> V_19 = V_20 ;
V_6 -> V_21 = 0 ;
V_6 -> V_22 = 0 ;
exit:
return V_1 ;
}
int F_7 ( struct V_1 * V_1 , T_1 * V_23 , T_2 V_24 )
{
struct V_5 * V_6 = & V_1 -> V_17 ;
T_3 V_25 ;
T_2 V_26 ;
V_25 = V_27 ;
V_26 = V_25 + V_6 -> V_21 ;
if ( V_26 + V_24 + 8 > V_28 ) {
F_3 ( L_3 ,
V_10 , V_26 + V_24 + 8 , V_28 ) ;
return V_29 ;
}
memcpy ( V_1 -> V_14 + V_25 + V_6 -> V_21 , V_23 , V_24 ) ;
V_6 -> V_21 += V_24 ;
V_6 -> V_22 += V_24 ;
return V_30 ;
}
bool F_8 ( struct V_2 * V_2 )
{
if ( 1 == V_2 -> V_31 . V_32 )
return true ;
if ( ( 2 == V_2 -> V_31 . V_32 ) && ( ! F_9 ( V_2 ) -> V_33 ) )
return true ;
return false ;
}
int F_10 ( struct V_2 * V_2 , struct V_1 * V_1 , T_2 V_34 , T_2 V_35 )
{
return F_11 ( V_2 , V_1 , V_34 , V_35 ) ;
}
int F_12 ( struct V_1 * V_1 , T_1 V_36 )
{
return V_30 ;
}
int F_13 ( struct V_1 * V_1 , T_3 V_37 , T_1 V_38 , T_1 V_39 )
{
struct V_40 V_41 = { 8 , V_42 , 0x0 , 0x0 , 0x0 } ;
V_41 . V_43 = F_14 ( V_37 ) ;
V_41 . V_44 = F_15 ( V_38 ) ;
if ( V_39 != 0xFF ) {
V_41 . V_45 = 12 ;
V_41 . V_39 = F_15 ( V_39 ) ;
}
return F_7 ( V_1 , ( T_1 * ) & V_41 , V_41 . V_45 ) ;
}
int F_16 ( struct V_1 * V_1 , T_3 V_37 , T_2 V_38 , T_2 V_39 )
{
struct V_40 V_41 = { 8 , V_46 , 0x0 , 0x0 , 0x0 } ;
V_41 . V_43 = F_14 ( V_37 ) ;
V_41 . V_44 = F_15 ( V_38 ) ;
if ( V_39 != 0xFFFFFFFF ) {
V_41 . V_45 = 12 ;
V_41 . V_39 = F_15 ( V_39 ) ;
}
return F_7 ( V_1 , ( T_1 * ) & V_41 , V_41 . V_45 ) ;
}
int F_17 ( struct V_1 * V_1 , T_1 V_47 , T_3 V_37 , T_2 V_38 , T_2 V_39 )
{
struct V_40 V_41 = { 8 , V_48 , 0x0 , 0x0 , 0x0 } ;
V_41 . V_43 = F_14 ( ( V_47 << 8 ) | ( ( V_37 ) & 0xFF ) ) ;
V_41 . V_44 = F_15 ( V_38 ) ;
if ( V_39 != 0x000FFFFF ) {
V_41 . V_45 = 12 ;
V_41 . V_39 = F_15 ( V_39 ) ;
}
return F_7 ( V_1 , ( T_1 * ) & V_41 , V_41 . V_45 ) ;
}
int F_18 ( struct V_1 * V_1 , T_3 V_49 )
{
struct V_40 V_41 = { 4 , V_50 , 0x0 , 0x0 , 0x0 } ;
V_41 . V_43 = F_14 ( V_49 ) ;
return F_7 ( V_1 , ( T_1 * ) & V_41 , 4 ) ;
}
int F_19 ( struct V_1 * V_1 , T_3 V_51 )
{
struct V_40 V_41 = { 4 , V_50 , 0x0 , 0x0 , 0x0 } ;
V_41 . V_43 = F_14 ( V_51 ) ;
return F_7 ( V_1 , ( T_1 * ) & V_41 , 4 ) ;
}
int F_20 ( struct V_1 * V_1 )
{
struct V_40 V_41 = { 4 , V_52 , F_14 ( 0xFFFF ) , F_15 ( 0xFF ) , 0x0 } ;
return F_7 ( V_1 , ( T_1 * ) & V_41 , 4 ) ;
}
T_1 F_21 ( struct V_1 * V_53 )
{
T_1 V_54 = false ;
if ( ( ( V_53 -> V_17 . V_21 + 32 ) % 256 ) + 8 >= 256 ) {
F_20 ( V_53 ) ;
V_53 -> V_17 . V_21 = ( ( ( ( V_53 -> V_17 . V_21 + 32 ) / 256 ) + 1 ) * 256 ) ;
V_53 -> V_17 . V_22 = V_53 -> V_17 . V_21 ;
V_54 = true ;
}
return V_54 ;
}
void F_22 ( struct V_2 * V_55 , int V_56 , T_1 * V_15 )
{
int V_57 ;
int V_58 = 1 ;
F_23 ( L_4 , V_10 ) ;
for ( V_57 = 0 ; V_57 < V_56 ; V_57 ++ ) {
F_24 ( L_5 , * ( V_15 + V_57 ) ) ;
if ( V_58 % 32 == 0 )
F_24 ( L_6 ) ;
V_58 ++ ;
}
F_24 ( L_6 ) ;
F_23 ( L_7 , V_56 ) ;
}
