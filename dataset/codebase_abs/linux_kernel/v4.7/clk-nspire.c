static void F_1 ( T_1 V_1 , struct V_2 * V_3 )
{
if ( F_2 ( V_1 , V_4 ) )
V_3 -> V_5 = 48 * V_6 ;
else
V_3 -> V_5 = 6 * F_2 ( V_1 , V_7 ) * V_6 ;
V_3 -> V_8 = F_2 ( V_1 , V_9 ) * F_2 ( V_1 , V_10 ) ;
V_3 -> V_11 = V_3 -> V_8 * ( F_2 ( V_1 , V_12 ) + 1 ) ;
}
static void F_3 ( T_1 V_1 , struct V_2 * V_3 )
{
if ( F_2 ( V_1 , V_4 ) )
V_3 -> V_5 = 27 * V_6 ;
else
V_3 -> V_5 = ( 300 - 6 * F_2 ( V_1 , V_13 ) ) * V_6 ;
V_3 -> V_8 = F_2 ( V_1 , V_9 ) * 2 ;
V_3 -> V_11 = V_3 -> V_8 * ( F_2 ( V_1 , V_12 ) + 1 ) ;
}
static void T_2 F_4 ( struct V_14 * V_15 ,
void (* F_5)( T_1 , struct V_2 * ) )
{
T_1 V_1 ;
void T_3 * V_16 ;
struct V_3 * V_3 ;
const char * V_17 = V_15 -> V_18 ;
const char * V_19 ;
struct V_2 V_20 ;
V_16 = F_6 ( V_15 , 0 ) ;
if ( ! V_16 )
return;
V_1 = F_7 ( V_16 ) ;
F_8 ( V_16 ) ;
F_5 ( V_1 , & V_20 ) ;
F_9 ( V_15 , L_1 , & V_17 ) ;
V_19 = F_10 ( V_15 , 0 ) ;
V_3 = F_11 ( NULL , V_17 , V_19 , 0 ,
1 , V_20 . V_11 ) ;
if ( ! F_12 ( V_3 ) )
F_13 ( V_15 , V_21 , V_3 ) ;
}
static void T_2 F_14 ( struct V_14 * V_15 )
{
F_4 ( V_15 , F_1 ) ;
}
static void T_2 F_15 ( struct V_14 * V_15 )
{
F_4 ( V_15 , F_3 ) ;
}
static void T_2 F_16 ( struct V_14 * V_15 ,
void (* F_5)( T_1 , struct V_2 * ) )
{
T_1 V_1 ;
void T_3 * V_16 ;
struct V_3 * V_3 ;
const char * V_17 = V_15 -> V_18 ;
struct V_2 V_20 ;
V_16 = F_6 ( V_15 , 0 ) ;
if ( ! V_16 )
return;
V_1 = F_7 ( V_16 ) ;
F_8 ( V_16 ) ;
F_5 ( V_1 , & V_20 ) ;
F_9 ( V_15 , L_1 , & V_17 ) ;
V_3 = F_17 ( NULL , V_17 , NULL , 0 , V_20 . V_5 ) ;
if ( ! F_12 ( V_3 ) )
F_13 ( V_15 , V_21 , V_3 ) ;
else
return;
F_18 ( L_2 ,
V_20 . V_5 / V_6 ,
V_20 . V_5 / V_20 . V_8 / V_6 ,
V_20 . V_5 / V_20 . V_11 / V_6 ) ;
}
static void T_2 F_19 ( struct V_14 * V_15 )
{
F_16 ( V_15 , F_1 ) ;
}
static void T_2 F_20 ( struct V_14 * V_15 )
{
F_16 ( V_15 , F_3 ) ;
}
