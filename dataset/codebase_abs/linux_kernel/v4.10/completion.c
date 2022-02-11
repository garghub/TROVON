void F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
F_2 ( & V_2 -> V_4 . V_5 , V_3 ) ;
V_2 -> V_6 ++ ;
F_3 ( & V_2 -> V_4 , V_7 , 1 ) ;
F_4 ( & V_2 -> V_4 . V_5 , V_3 ) ;
}
void F_5 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
F_2 ( & V_2 -> V_4 . V_5 , V_3 ) ;
V_2 -> V_6 += V_8 / 2 ;
F_3 ( & V_2 -> V_4 , V_7 , 0 ) ;
F_4 ( & V_2 -> V_4 . V_5 , V_3 ) ;
}
static inline long T_1
F_6 ( struct V_1 * V_2 ,
long (* F_7)( long ) , long V_9 , int V_10 )
{
if ( ! V_2 -> V_6 ) {
F_8 ( V_4 , V_11 ) ;
F_9 ( & V_2 -> V_4 , & V_4 ) ;
do {
if ( F_10 ( V_10 , V_11 ) ) {
V_9 = - V_12 ;
break;
}
F_11 ( V_10 ) ;
F_12 ( & V_2 -> V_4 . V_5 ) ;
V_9 = F_7 ( V_9 ) ;
F_13 ( & V_2 -> V_4 . V_5 ) ;
} while ( ! V_2 -> V_6 && V_9 );
F_14 ( & V_2 -> V_4 , & V_4 ) ;
if ( ! V_2 -> V_6 )
return V_9 ;
}
V_2 -> V_6 -- ;
return V_9 ? : 1 ;
}
static inline long T_1
F_15 ( struct V_1 * V_2 ,
long (* F_7)( long ) , long V_9 , int V_10 )
{
F_16 () ;
F_13 ( & V_2 -> V_4 . V_5 ) ;
V_9 = F_6 ( V_2 , F_7 , V_9 , V_10 ) ;
F_12 ( & V_2 -> V_4 . V_5 ) ;
return V_9 ;
}
static long T_1
F_17 ( struct V_1 * V_2 , long V_9 , int V_10 )
{
return F_15 ( V_2 , V_13 , V_9 , V_10 ) ;
}
static long T_1
F_18 ( struct V_1 * V_2 , long V_9 , int V_10 )
{
return F_15 ( V_2 , V_14 , V_9 , V_10 ) ;
}
void T_1 F_19 ( struct V_1 * V_2 )
{
F_17 ( V_2 , V_15 , V_16 ) ;
}
unsigned long T_1
F_20 ( struct V_1 * V_2 , unsigned long V_9 )
{
return F_17 ( V_2 , V_9 , V_16 ) ;
}
void T_1 F_21 ( struct V_1 * V_2 )
{
F_18 ( V_2 , V_15 , V_16 ) ;
}
unsigned long T_1
F_22 ( struct V_1 * V_2 , unsigned long V_9 )
{
return F_18 ( V_2 , V_9 , V_16 ) ;
}
int T_1 F_23 ( struct V_1 * V_2 )
{
long V_17 = F_17 ( V_2 , V_15 , V_18 ) ;
if ( V_17 == - V_12 )
return V_17 ;
return 0 ;
}
long T_1
F_24 ( struct V_1 * V_2 ,
unsigned long V_9 )
{
return F_17 ( V_2 , V_9 , V_18 ) ;
}
int T_1 F_25 ( struct V_1 * V_2 )
{
long V_17 = F_17 ( V_2 , V_15 , V_19 ) ;
if ( V_17 == - V_12 )
return V_17 ;
return 0 ;
}
long T_1
F_26 ( struct V_1 * V_2 ,
unsigned long V_9 )
{
return F_17 ( V_2 , V_9 , V_19 ) ;
}
bool F_27 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
int V_20 = 1 ;
if ( ! F_28 ( V_2 -> V_6 ) )
return 0 ;
F_2 ( & V_2 -> V_4 . V_5 , V_3 ) ;
if ( ! V_2 -> V_6 )
V_20 = 0 ;
else
V_2 -> V_6 -- ;
F_4 ( & V_2 -> V_4 . V_5 , V_3 ) ;
return V_20 ;
}
bool F_29 ( struct V_1 * V_2 )
{
if ( ! F_28 ( V_2 -> V_6 ) )
return false ;
F_30 () ;
F_31 ( & V_2 -> V_4 . V_5 ) ;
return true ;
}
