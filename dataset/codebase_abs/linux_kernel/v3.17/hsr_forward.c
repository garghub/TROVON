static bool F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
F_2 ( ! F_3 ( V_4 ) ) ;
V_6 = (struct V_5 * ) F_4 ( V_4 ) ;
if ( ! F_5 ( V_6 -> V_7 . V_8 ,
V_2 -> V_9 ) )
return false ;
if ( F_6 ( & V_6 -> V_10 ) != 0x0f )
return false ;
if ( ( V_6 -> V_10 . V_11 != V_12 ) &&
( V_6 -> V_10 . V_11 != V_13 ) )
return false ;
if ( V_6 -> V_10 . V_14 != 12 )
return false ;
return true ;
}
static struct V_3 * F_7 ( struct V_3 * V_15 ,
struct V_16 * V_17 )
{
struct V_3 * V_4 ;
int V_18 ;
unsigned char * V_19 , * V_20 ;
F_8 ( V_15 , V_21 ) ;
V_4 = F_9 ( V_15 , F_10 ( V_15 ) - V_21 , V_22 ) ;
F_11 ( V_15 , V_21 ) ;
if ( V_4 == NULL )
return NULL ;
F_12 ( V_4 ) ;
if ( V_4 -> V_23 == V_24 )
V_4 -> V_25 -= V_21 ;
V_18 = 2 * V_26 ;
if ( V_17 -> V_27 )
V_18 += V_28 ;
V_20 = F_4 ( V_15 ) ;
V_19 = F_4 ( V_4 ) ;
memcpy ( V_19 , V_20 , V_18 ) ;
V_4 -> V_29 = F_13 ( V_4 ) -> V_30 ;
return V_4 ;
}
static struct V_3 * F_14 ( struct V_16 * V_17 ,
struct V_31 * V_32 )
{
if ( ! V_17 -> V_33 )
V_17 -> V_33 = F_7 ( V_17 -> V_34 , V_17 ) ;
return F_15 ( V_17 -> V_33 , V_22 ) ;
}
static void F_16 ( struct V_3 * V_4 , struct V_16 * V_17 ,
struct V_31 * V_32 )
{
struct V_35 * V_35 ;
int V_36 ;
int V_37 ;
if ( V_32 -> type == V_38 )
V_36 = 0 ;
else
V_36 = 1 ;
V_37 = V_4 -> V_39 - 14 ;
if ( V_17 -> V_27 )
V_37 -= 4 ;
V_35 = (struct V_35 * ) F_4 ( V_4 ) ;
F_17 ( & V_35 -> V_40 , V_36 ) ;
F_18 ( & V_35 -> V_40 , V_37 ) ;
V_35 -> V_40 . V_41 = F_19 ( V_17 -> V_41 ) ;
V_35 -> V_40 . V_42 = V_35 -> V_7 . V_30 ;
V_35 -> V_7 . V_30 = F_19 ( V_43 ) ;
}
static struct V_3 * F_20 ( struct V_3 * V_44 ,
struct V_16 * V_17 ,
struct V_31 * V_32 )
{
int V_45 ;
unsigned char * V_19 , * V_20 ;
struct V_3 * V_4 ;
V_4 = F_9 ( V_44 , F_10 ( V_44 ) + V_21 , V_22 ) ;
if ( V_4 == NULL )
return NULL ;
F_12 ( V_4 ) ;
if ( V_4 -> V_23 == V_24 )
V_4 -> V_25 += V_21 ;
V_45 = V_46 ;
if ( V_17 -> V_27 )
V_45 += V_28 ;
V_20 = F_4 ( V_4 ) ;
V_19 = F_11 ( V_4 , V_21 ) ;
memmove ( V_19 , V_20 , V_45 ) ;
F_12 ( V_4 ) ;
F_16 ( V_4 , V_17 , V_32 ) ;
return V_4 ;
}
static struct V_3 * F_21 ( struct V_16 * V_17 ,
struct V_31 * V_32 )
{
if ( V_17 -> V_34 )
return F_15 ( V_17 -> V_34 , V_22 ) ;
if ( ( V_32 -> type != V_38 ) && ( V_32 -> type != V_47 ) ) {
F_22 ( 1 , L_1 ) ;
return NULL ;
}
return F_20 ( V_17 -> V_33 , V_17 , V_32 ) ;
}
static void F_23 ( struct V_3 * V_4 , struct V_48 * V_49 ,
struct V_50 * V_51 )
{
bool V_52 ;
int V_53 ;
V_52 = ( V_4 -> V_54 == V_55 ) ;
F_24 ( V_51 , V_4 ) ;
F_8 ( V_4 , V_46 ) ;
V_53 = F_25 ( V_4 ) ;
if ( V_53 == V_56 ) {
V_49 -> V_57 . V_58 ++ ;
} else {
V_49 -> V_57 . V_59 ++ ;
V_49 -> V_57 . V_60 += V_4 -> V_39 ;
if ( V_52 )
V_49 -> V_57 . V_61 ++ ;
}
}
static int F_26 ( struct V_3 * V_4 , struct V_31 * V_32 ,
struct V_16 * V_17 )
{
if ( V_17 -> V_62 -> type == V_63 ) {
F_27 ( V_17 -> V_51 , V_4 , V_32 ) ;
F_28 ( F_13 ( V_4 ) -> V_64 , V_32 -> V_49 -> V_65 ) ;
}
return F_29 ( V_4 ) ;
}
static void F_30 ( struct V_16 * V_17 )
{
struct V_31 * V_32 ;
struct V_3 * V_4 ;
F_31 (frame->port_rcv->hsr, port) {
if ( V_32 == V_17 -> V_62 )
continue;
if ( ( V_32 -> type == V_63 ) && ! V_17 -> V_66 )
continue;
if ( ( V_32 -> type != V_63 ) && V_17 -> V_67 )
continue;
if ( F_32 ( V_32 , V_17 -> V_51 ,
V_17 -> V_41 ) )
continue;
if ( V_17 -> V_68 && ( V_32 -> type == V_63 ) ) {
F_33 ( V_17 -> V_34 ,
V_17 -> V_51 ,
V_17 -> V_62 ) ;
continue;
}
if ( V_32 -> type != V_63 )
V_4 = F_21 ( V_17 , V_32 ) ;
else
V_4 = F_14 ( V_17 , V_32 ) ;
if ( V_4 == NULL ) {
continue;
}
V_4 -> V_49 = V_32 -> V_49 ;
if ( V_32 -> type == V_63 )
F_23 ( V_4 , V_32 -> V_49 , V_17 -> V_51 ) ;
else
F_26 ( V_4 , V_32 , V_17 ) ;
}
}
static void F_34 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_16 * V_17 )
{
struct V_48 * V_69 ;
V_69 = F_35 ( V_2 , V_63 ) -> V_49 ;
if ( F_36 ( V_2 , F_13 ( V_4 ) -> V_8 ) ) {
V_17 -> V_67 = true ;
V_4 -> V_54 = V_70 ;
} else {
V_17 -> V_67 = false ;
}
if ( ( V_4 -> V_54 == V_70 ) ||
( V_4 -> V_54 == V_55 ) ||
( V_4 -> V_54 == V_71 ) ) {
V_17 -> V_66 = true ;
} else {
V_17 -> V_66 = false ;
}
}
static int F_37 ( struct V_16 * V_17 ,
struct V_3 * V_4 , struct V_31 * V_32 )
{
struct V_7 * V_7 ;
unsigned long V_72 ;
V_17 -> V_68 = F_1 ( V_32 -> V_2 , V_4 ) ;
V_17 -> V_51 = F_38 ( & V_32 -> V_2 -> V_73 , V_4 ,
V_17 -> V_68 ) ;
if ( V_17 -> V_51 == NULL )
return - 1 ;
V_7 = (struct V_7 * ) F_4 ( V_4 ) ;
V_17 -> V_27 = false ;
if ( V_7 -> V_30 == F_19 ( V_74 ) ) {
V_17 -> V_27 = true ;
F_22 ( 1 , L_2 ) ;
}
if ( V_7 -> V_30 == F_19 ( V_43 ) ) {
V_17 -> V_33 = NULL ;
V_17 -> V_34 = V_4 ;
V_17 -> V_41 = F_39 ( V_4 ) ;
} else {
V_17 -> V_33 = V_4 ;
V_17 -> V_34 = NULL ;
F_40 ( & V_32 -> V_2 -> V_75 , V_72 ) ;
V_17 -> V_41 = V_32 -> V_2 -> V_41 ;
V_32 -> V_2 -> V_41 ++ ;
F_41 ( & V_32 -> V_2 -> V_75 , V_72 ) ;
}
V_17 -> V_62 = V_32 ;
F_34 ( V_32 -> V_2 , V_4 , V_17 ) ;
return 0 ;
}
void F_42 ( struct V_3 * V_4 , struct V_31 * V_32 )
{
struct V_16 V_17 ;
if ( F_4 ( V_4 ) != V_4 -> V_76 ) {
F_22 ( 1 , L_3 ,
__FILE__ , __LINE__ , V_32 -> V_49 -> V_77 ) ;
goto V_78;
}
if ( F_37 ( & V_17 , V_4 , V_32 ) < 0 )
goto V_78;
F_43 ( V_17 . V_51 , V_32 , V_17 . V_41 ) ;
F_30 ( & V_17 ) ;
if ( V_17 . V_34 != NULL )
F_44 ( V_17 . V_34 ) ;
if ( V_17 . V_33 != NULL )
F_44 ( V_17 . V_33 ) ;
return;
V_78:
V_32 -> V_49 -> V_57 . V_79 ++ ;
F_44 ( V_4 ) ;
}
