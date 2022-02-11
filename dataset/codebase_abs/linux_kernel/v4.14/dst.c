int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 , struct V_4 * V_5 )
{
F_2 ( V_5 ) ;
return 0 ;
}
void F_3 ( struct V_6 * V_7 , struct V_8 * V_9 ,
struct V_10 * V_11 , int V_12 , int V_13 ,
unsigned short V_14 )
{
V_7 -> V_15 = NULL ;
V_7 -> V_11 = V_11 ;
if ( V_11 )
F_4 ( V_11 ) ;
V_7 -> V_9 = V_9 ;
F_5 ( V_7 , V_16 . V_17 , true ) ;
V_7 -> V_18 = 0UL ;
V_7 -> V_19 = V_7 ;
V_7 -> V_20 = NULL ;
#ifdef F_6
V_7 -> V_21 = NULL ;
#endif
V_7 -> V_22 = V_23 ;
V_7 -> V_24 = F_1 ;
V_7 -> error = 0 ;
V_7 -> V_25 = V_13 ;
V_7 -> V_26 = 0 ;
V_7 -> V_27 = 0 ;
#ifdef F_7
V_7 -> V_28 = 0 ;
#endif
V_7 -> V_29 = NULL ;
F_8 ( & V_7 -> V_30 , V_12 ) ;
V_7 -> V_31 = 0 ;
V_7 -> V_32 = V_33 ;
V_7 -> V_14 = V_14 ;
V_7 -> V_34 = NULL ;
if ( ! ( V_14 & V_35 ) )
F_9 ( V_9 , 1 ) ;
}
void * F_10 ( struct V_8 * V_9 , struct V_10 * V_11 ,
int V_12 , int V_13 , unsigned short V_14 )
{
struct V_6 * V_7 ;
if ( V_9 -> V_36 && F_11 ( V_9 ) > V_9 -> V_37 ) {
if ( V_9 -> V_36 ( V_9 ) )
return NULL ;
}
V_7 = F_12 ( V_9 -> V_38 , V_39 ) ;
if ( ! V_7 )
return NULL ;
F_3 ( V_7 , V_9 , V_11 , V_12 , V_13 , V_14 ) ;
return V_7 ;
}
struct V_6 * F_13 ( struct V_6 * V_7 )
{
struct V_6 * V_15 ;
F_14 () ;
V_15 = V_7 -> V_15 ;
if ( ! ( V_7 -> V_14 & V_35 ) )
F_9 ( V_7 -> V_9 , - 1 ) ;
if ( V_7 -> V_9 -> V_40 )
V_7 -> V_9 -> V_40 ( V_7 ) ;
if ( V_7 -> V_11 )
F_15 ( V_7 -> V_11 ) ;
F_16 ( V_7 -> V_29 ) ;
if ( V_7 -> V_14 & V_41 )
F_17 ( (struct V_42 * ) V_7 ) ;
else
F_18 ( V_7 -> V_9 -> V_38 , V_7 ) ;
V_7 = V_15 ;
if ( V_7 )
F_19 ( V_7 ) ;
return NULL ;
}
static void F_20 ( struct V_43 * V_44 )
{
struct V_6 * V_7 = F_21 ( V_44 , struct V_6 , V_43 ) ;
V_7 = F_13 ( V_7 ) ;
}
void F_22 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = V_7 -> V_11 ;
V_7 -> V_25 = V_45 ;
if ( V_7 -> V_9 -> V_46 )
V_7 -> V_9 -> V_46 ( V_7 , V_11 , true ) ;
V_7 -> V_22 = V_23 ;
V_7 -> V_24 = F_1 ;
V_7 -> V_11 = F_23 ( V_7 -> V_11 ) -> V_47 ;
F_4 ( V_7 -> V_11 ) ;
F_15 ( V_11 ) ;
}
void F_24 ( struct V_6 * V_7 )
{
if ( V_7 ) {
int V_48 ;
V_48 = F_25 ( & V_7 -> V_30 ) ;
if ( F_26 ( V_48 < 0 ) )
F_27 ( L_1 ,
V_49 , V_7 , V_48 ) ;
if ( ! V_48 )
F_28 ( & V_7 -> V_43 , F_20 ) ;
}
}
void F_19 ( struct V_6 * V_7 )
{
if ( V_7 ) {
int V_48 ;
V_48 = F_25 ( & V_7 -> V_30 ) ;
if ( F_26 ( V_48 < 0 ) )
F_27 ( L_1 ,
V_49 , V_7 , V_48 ) ;
if ( ! V_48 )
F_13 ( V_7 ) ;
}
}
T_1 * F_29 ( struct V_6 * V_7 , unsigned long V_50 )
{
struct V_51 * V_52 = F_30 ( sizeof( * V_52 ) , V_39 ) ;
if ( V_52 ) {
struct V_51 * V_53 = (struct V_51 * ) F_31 ( V_50 ) ;
unsigned long V_54 , V_55 ;
F_32 ( & V_52 -> V_56 , 1 ) ;
memcpy ( V_52 -> V_17 , V_53 -> V_17 , sizeof( V_52 -> V_17 ) ) ;
V_55 = ( unsigned long ) V_52 ;
V_54 = F_33 ( & V_7 -> V_57 , V_50 , V_55 ) ;
if ( V_54 != V_50 ) {
F_34 ( V_52 ) ;
V_52 = (struct V_51 * ) F_31 ( V_54 ) ;
if ( V_54 & V_58 )
V_52 = NULL ;
} else if ( V_54 & V_59 ) {
if ( F_35 ( & V_53 -> V_56 ) )
F_34 ( V_53 ) ;
}
}
F_36 ( F_37 ( struct V_51 , V_17 ) != 0 ) ;
return ( T_1 * ) V_52 ;
}
void F_38 ( struct V_6 * V_7 , unsigned long V_50 )
{
unsigned long V_54 , V_55 ;
V_55 = ( ( unsigned long ) & V_16 ) | V_58 ;
V_54 = F_33 ( & V_7 -> V_57 , V_50 , V_55 ) ;
if ( V_54 == V_50 )
F_34 ( F_31 ( V_50 ) ) ;
}
static int F_39 ( struct V_1 * V_1 , struct V_2 * V_3 , struct V_4 * V_5 )
{
F_40 ( 1 , L_2 ) ;
F_2 ( V_5 ) ;
return 0 ;
}
static int F_41 ( struct V_4 * V_5 )
{
F_40 ( 1 , L_3 ) ;
F_2 ( V_5 ) ;
return 0 ;
}
static void F_42 ( struct V_42 * V_60 ,
enum V_61 type , T_2 V_62 )
{
struct V_6 * V_7 ;
V_7 = & V_60 -> V_7 ;
F_3 ( V_7 , & V_63 , NULL , 1 , V_64 ,
V_41 | V_35 ) ;
V_7 -> V_22 = F_41 ;
V_7 -> V_24 = F_39 ;
memset ( V_7 + 1 , 0 , sizeof( * V_60 ) + V_62 - sizeof( * V_7 ) ) ;
V_60 -> type = type ;
}
struct V_42 * F_43 ( T_2 V_62 , enum V_61 type ,
T_3 V_14 )
{
struct V_42 * V_60 ;
V_60 = F_30 ( sizeof( * V_60 ) + V_62 , V_14 ) ;
if ( ! V_60 )
return NULL ;
F_42 ( V_60 , type , V_62 ) ;
return V_60 ;
}
void F_17 ( struct V_42 * V_60 )
{
#ifdef F_44
if ( V_60 -> type == V_65 )
F_45 ( & V_60 -> V_66 . V_67 . V_68 ) ;
#endif
F_34 ( V_60 ) ;
}
struct V_42 T_4 *
F_46 ( T_2 V_62 , enum V_61 type , T_3 V_14 )
{
int V_69 ;
struct V_42 T_4 * V_60 ;
V_60 = F_47 ( sizeof( struct V_42 ) + V_62 ,
F_48 ( struct V_42 ) , V_14 ) ;
if ( ! V_60 )
return NULL ;
F_49 (cpu)
F_42 ( F_50 ( V_60 , V_69 ) , type , V_62 ) ;
return V_60 ;
}
