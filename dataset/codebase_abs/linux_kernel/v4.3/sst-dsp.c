void F_1 ( void T_1 * V_1 , T_2 V_2 , T_2 V_3 )
{
F_2 ( V_3 , V_1 + V_2 ) ;
}
T_2 F_3 ( void T_1 * V_1 , T_2 V_2 )
{
return F_4 ( V_1 + V_2 ) ;
}
void F_5 ( void T_1 * V_1 , T_2 V_2 , T_3 V_3 )
{
F_6 ( V_1 + V_2 , & V_3 , sizeof( V_3 ) ) ;
}
T_3 F_7 ( void T_1 * V_1 , T_2 V_2 )
{
T_3 V_4 ;
F_8 ( & V_4 , V_1 + V_2 , sizeof( V_4 ) ) ;
return V_4 ;
}
static inline void F_9 ( volatile T_2 T_1 * V_5 ,
T_2 * V_6 , T_4 V_7 )
{
int V_8 , V_9 = V_7 >> 2 ;
for ( V_8 = 0 ; V_8 < V_9 ; V_8 ++ )
F_2 ( V_6 [ V_8 ] , V_5 + V_8 ) ;
}
static inline void F_10 ( T_2 * V_5 ,
const volatile T_1 T_2 * V_6 , T_4 V_7 )
{
int V_8 , V_9 = V_7 >> 2 ;
for ( V_8 = 0 ; V_8 < V_9 ; V_8 ++ )
V_5 [ V_8 ] = F_4 ( V_6 + V_8 ) ;
}
void F_11 ( struct V_10 * V_11 ,
void T_1 * V_5 , void * V_6 , T_4 V_7 )
{
F_9 ( V_5 , V_6 , V_7 ) ;
}
void F_12 ( struct V_10 * V_11 , void * V_5 ,
void T_1 * V_6 , T_4 V_7 )
{
F_10 ( V_5 , V_6 , V_7 ) ;
}
void F_13 ( struct V_10 * V_11 , T_2 V_2 , T_2 V_3 )
{
unsigned long V_12 ;
F_14 ( & V_11 -> V_13 , V_12 ) ;
V_11 -> V_14 -> V_15 ( V_11 -> V_1 . V_16 , V_2 , V_3 ) ;
F_15 ( & V_11 -> V_13 , V_12 ) ;
}
T_2 F_16 ( struct V_10 * V_11 , T_2 V_2 )
{
unsigned long V_12 ;
T_2 V_4 ;
F_14 ( & V_11 -> V_13 , V_12 ) ;
V_4 = V_11 -> V_14 -> V_17 ( V_11 -> V_1 . V_16 , V_2 ) ;
F_15 ( & V_11 -> V_13 , V_12 ) ;
return V_4 ;
}
void F_17 ( struct V_10 * V_11 , T_2 V_2 , T_3 V_3 )
{
unsigned long V_12 ;
F_14 ( & V_11 -> V_13 , V_12 ) ;
V_11 -> V_14 -> V_18 ( V_11 -> V_1 . V_16 , V_2 , V_3 ) ;
F_15 ( & V_11 -> V_13 , V_12 ) ;
}
T_3 F_18 ( struct V_10 * V_11 , T_2 V_2 )
{
unsigned long V_12 ;
T_3 V_4 ;
F_14 ( & V_11 -> V_13 , V_12 ) ;
V_4 = V_11 -> V_14 -> V_19 ( V_11 -> V_1 . V_16 , V_2 ) ;
F_15 ( & V_11 -> V_13 , V_12 ) ;
return V_4 ;
}
void F_19 ( struct V_10 * V_11 , T_2 V_2 , T_2 V_3 )
{
V_11 -> V_14 -> V_15 ( V_11 -> V_1 . V_16 , V_2 , V_3 ) ;
}
T_2 F_20 ( struct V_10 * V_11 , T_2 V_2 )
{
return V_11 -> V_14 -> V_17 ( V_11 -> V_1 . V_16 , V_2 ) ;
}
void F_21 ( struct V_10 * V_11 , T_2 V_2 , T_3 V_3 )
{
V_11 -> V_14 -> V_18 ( V_11 -> V_1 . V_16 , V_2 , V_3 ) ;
}
T_3 F_22 ( struct V_10 * V_11 , T_2 V_2 )
{
return V_11 -> V_14 -> V_19 ( V_11 -> V_1 . V_16 , V_2 ) ;
}
int F_23 ( struct V_10 * V_11 , T_2 V_2 ,
T_2 V_20 , T_2 V_3 )
{
bool V_21 ;
unsigned int V_22 , V_23 ;
T_2 V_24 ;
V_24 = F_20 ( V_11 , V_2 ) ;
V_22 = V_24 ;
V_23 = ( V_22 & ( ~ V_20 ) ) | ( V_3 & V_20 ) ;
V_21 = ( V_22 != V_23 ) ;
if ( V_21 )
F_19 ( V_11 , V_2 , V_23 ) ;
return V_21 ;
}
int F_24 ( struct V_10 * V_11 , T_2 V_2 ,
T_3 V_20 , T_3 V_3 )
{
bool V_21 ;
T_3 V_22 , V_23 ;
V_22 = F_22 ( V_11 , V_2 ) ;
V_23 = ( V_22 & ( ~ V_20 ) ) | ( V_3 & V_20 ) ;
V_21 = ( V_22 != V_23 ) ;
if ( V_21 )
F_21 ( V_11 , V_2 , V_23 ) ;
return V_21 ;
}
void F_25 ( struct V_10 * V_11 , T_2 V_2 ,
T_2 V_20 , T_2 V_3 )
{
unsigned int V_22 , V_23 ;
T_2 V_24 ;
V_24 = F_20 ( V_11 , V_2 ) ;
V_22 = V_24 ;
V_23 = ( V_22 & ( ~ V_20 ) ) | ( V_3 & V_20 ) ;
F_19 ( V_11 , V_2 , V_23 ) ;
}
int F_26 ( struct V_10 * V_11 , T_2 V_2 ,
T_2 V_20 , T_2 V_3 )
{
unsigned long V_12 ;
bool V_21 ;
F_14 ( & V_11 -> V_13 , V_12 ) ;
V_21 = F_23 ( V_11 , V_2 , V_20 , V_3 ) ;
F_15 ( & V_11 -> V_13 , V_12 ) ;
return V_21 ;
}
int F_27 ( struct V_10 * V_11 , T_2 V_2 ,
T_3 V_20 , T_3 V_3 )
{
unsigned long V_12 ;
bool V_21 ;
F_14 ( & V_11 -> V_13 , V_12 ) ;
V_21 = F_24 ( V_11 , V_2 , V_20 , V_3 ) ;
F_15 ( & V_11 -> V_13 , V_12 ) ;
return V_21 ;
}
void F_28 ( struct V_10 * V_11 , T_2 V_2 ,
T_2 V_20 , T_2 V_3 )
{
unsigned long V_12 ;
F_14 ( & V_11 -> V_13 , V_12 ) ;
F_25 ( V_11 , V_2 , V_20 , V_3 ) ;
F_15 ( & V_11 -> V_13 , V_12 ) ;
}
int F_29 ( struct V_10 * V_25 , T_2 V_2 , T_2 V_20 ,
T_2 V_26 , T_2 V_27 , char * V_28 )
{
int time , V_24 ;
T_2 V_29 ;
bool V_30 = false ;
for ( time = 0 ; time < 5 ; time ++ ) {
if ( ( F_20 ( V_25 , V_2 ) & V_20 ) == V_26 ) {
V_30 = true ;
break;
}
F_30 ( 1 ) ;
}
if ( V_30 == false ) {
V_27 /= 10 ;
for ( time = 0 ; time < V_27 ; time ++ ) {
if ( ( F_20 ( V_25 , V_2 ) & V_20 ) == V_26 )
break;
F_31 ( 5000 , 10000 ) ;
}
}
V_29 = F_20 ( V_25 , V_2 ) ;
F_32 ( V_25 -> V_31 , L_1 , V_29 , V_28 ,
( time < V_27 ) ? L_2 : L_3 ) ;
V_24 = time < V_27 ? 0 : - V_32 ;
return V_24 ;
}
void F_33 ( struct V_10 * V_11 )
{
if ( V_11 -> V_14 -> V_33 )
V_11 -> V_14 -> V_33 ( V_11 ) ;
}
void F_34 ( struct V_10 * V_11 )
{
if ( V_11 -> V_14 -> V_34 )
V_11 -> V_14 -> V_34 ( V_11 ) ;
}
int F_35 ( struct V_10 * V_11 )
{
if ( V_11 -> V_14 -> V_35 )
V_11 -> V_14 -> V_35 ( V_11 ) ;
return 0 ;
}
int F_36 ( struct V_10 * V_11 )
{
if ( V_11 -> V_14 -> V_36 )
return V_11 -> V_14 -> V_36 ( V_11 ) ;
return 0 ;
}
void F_37 ( struct V_10 * V_11 )
{
if ( V_11 -> V_14 -> V_37 )
V_11 -> V_14 -> V_37 ( V_11 ) ;
}
void F_38 ( struct V_10 * V_11 )
{
if ( V_11 -> V_14 -> V_38 )
V_11 -> V_14 -> V_38 ( V_11 ) ;
}
void F_39 ( struct V_10 * V_39 , T_2 V_40 )
{
F_19 ( V_39 , V_41 , V_40 | V_42 ) ;
F_40 ( V_40 ) ;
}
T_2 F_41 ( struct V_10 * V_39 )
{
T_2 V_40 ;
V_40 = F_20 ( V_39 , V_41 ) ;
F_42 ( V_40 ) ;
return V_40 ;
}
int F_43 ( struct V_10 * V_11 , T_2 V_43 , T_4 V_44 ,
T_2 V_45 , T_4 V_46 )
{
V_11 -> V_47 . V_48 = V_11 -> V_1 . V_49 + V_43 ;
V_11 -> V_47 . V_50 = V_11 -> V_1 . V_49 + V_45 ;
V_11 -> V_47 . V_51 = V_44 ;
V_11 -> V_47 . V_52 = V_46 ;
return 0 ;
}
void F_44 ( struct V_10 * V_11 , void * V_53 , T_4 V_7 )
{
T_2 V_8 ;
F_45 ( V_7 ) ;
F_6 ( V_11 -> V_47 . V_50 , V_53 , V_7 ) ;
for ( V_8 = 0 ; V_8 < V_7 ; V_8 += 4 )
F_46 ( V_8 , * ( T_2 * ) ( V_53 + V_8 ) ) ;
}
void F_47 ( struct V_10 * V_11 , void * V_53 , T_4 V_7 )
{
T_2 V_8 ;
F_48 ( V_7 ) ;
F_8 ( V_53 , V_11 -> V_47 . V_50 , V_7 ) ;
for ( V_8 = 0 ; V_8 < V_7 ; V_8 += 4 )
F_49 ( V_8 , * ( T_2 * ) ( V_53 + V_8 ) ) ;
}
void F_50 ( struct V_10 * V_11 , void * V_53 , T_4 V_7 )
{
T_2 V_8 ;
F_51 ( V_7 ) ;
F_6 ( V_11 -> V_47 . V_48 , V_53 , V_7 ) ;
for ( V_8 = 0 ; V_8 < V_7 ; V_8 += 4 )
F_52 ( V_8 , * ( T_2 * ) ( V_53 + V_8 ) ) ;
}
void F_53 ( struct V_10 * V_11 , void * V_53 , T_4 V_7 )
{
T_2 V_8 ;
F_54 ( V_7 ) ;
F_8 ( V_53 , V_11 -> V_47 . V_48 , V_7 ) ;
for ( V_8 = 0 ; V_8 < V_7 ; V_8 += 4 )
F_55 ( V_8 , * ( T_2 * ) ( V_53 + V_8 ) ) ;
}
struct V_10 * F_56 ( struct V_54 * V_31 ,
struct V_55 * V_56 , struct V_57 * V_58 )
{
struct V_10 * V_11 ;
int V_59 ;
F_57 ( V_31 , L_4 , V_58 -> V_60 ) ;
V_11 = F_58 ( V_31 , sizeof( * V_11 ) , V_61 ) ;
if ( V_11 == NULL )
return NULL ;
F_59 ( & V_11 -> V_13 ) ;
F_60 ( & V_11 -> V_62 ) ;
V_11 -> V_31 = V_31 ;
V_11 -> V_63 = V_58 -> V_63 ;
V_11 -> V_64 = V_56 -> V_64 ;
V_11 -> V_56 = V_56 ;
V_11 -> V_60 = V_58 -> V_60 ;
V_11 -> V_65 = V_58 -> V_65 ;
V_11 -> V_14 = V_56 -> V_14 ;
V_11 -> V_58 = V_58 ;
F_61 ( & V_11 -> V_66 ) ;
F_61 ( & V_11 -> V_67 ) ;
F_61 ( & V_11 -> V_68 ) ;
F_61 ( & V_11 -> V_69 ) ;
F_61 ( & V_11 -> V_70 ) ;
if ( V_11 -> V_14 -> V_71 ) {
V_59 = V_11 -> V_14 -> V_71 ( V_11 , V_58 ) ;
if ( V_59 < 0 )
return NULL ;
}
V_59 = F_62 ( V_11 -> V_65 , V_11 -> V_14 -> V_72 ,
V_56 -> V_73 , V_74 , L_5 , V_11 ) ;
if ( V_59 )
goto V_75;
V_59 = F_63 ( V_11 ) ;
if ( V_59 )
F_64 ( V_31 , L_6 , V_59 ) ;
return V_11 ;
V_75:
if ( V_11 -> V_14 -> free )
V_11 -> V_14 -> free ( V_11 ) ;
return NULL ;
}
void F_65 ( struct V_10 * V_11 )
{
F_66 ( V_11 -> V_65 , V_11 ) ;
if ( V_11 -> V_14 -> free )
V_11 -> V_14 -> free ( V_11 ) ;
F_67 ( V_11 -> V_76 ) ;
}
